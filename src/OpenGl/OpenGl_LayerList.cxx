// Created on: 2014-02-02
// Created by: Anton POLETAEV
// Copyright (c) -1999 Matra Datavision
// Copyright (c) 2014-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and / or modify it
// under the terms of the GNU Lesser General Public version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifdef HAVE_CONFIG_H
  #include <oce-config.h>
#endif

#include <OpenGl_GlCore11.hxx>

#include <OpenGl_LayerList.hxx>
#include <OpenGl_Structure.hxx>

#include <InterfaceGraphic_Graphic3d.hxx>
#include <InterfaceGraphic.hxx>

//=======================================================================
//function : OpenGl_LayerList
//purpose  : Constructor
//=======================================================================

OpenGl_LayerList::OpenGl_LayerList (const Standard_Integer theNbPriorities)
 : myNbPriorities (theNbPriorities),
   myNbStructures (0)
{
  // insert default priority layer
  myLayers.Append (OpenGl_PriorityList (myNbPriorities));
  myLayerIds.Bind (0, myLayers.Length());
}

//=======================================================================
//function : ~OpenGl_LayerList
//purpose  : Destructor
//=======================================================================

OpenGl_LayerList::~OpenGl_LayerList ()
{
}

//=======================================================================
//function : defaultLayer
//purpose  :
//=======================================================================

OpenGl_PriorityList& OpenGl_LayerList::defaultLayer()
{
  return myLayers.ChangeValue (1);
}

//=======================================================================
//function : NbPriorities
//purpose  : Method returns the number of available priorities
//=======================================================================

Standard_Integer OpenGl_LayerList::NbPriorities () const
{
  return myNbPriorities;
}

//=======================================================================
//function : NbStructures
//purpose  : Method returns the number of available structures
//=======================================================================

Standard_Integer OpenGl_LayerList::NbStructures () const
{
  return myNbStructures;
}

//=======================================================================
//function : AddLayer
//purpose  : 
//=======================================================================

void OpenGl_LayerList::AddLayer (const Standard_Integer theLayerId)
{
  if (HasLayer (theLayerId))
    return;

  // add the new layer
  myLayers.Append (OpenGl_PriorityList (myNbPriorities));
  myLayerIds.Bind (theLayerId, myLayers.Length());
}

//=======================================================================
//function : HasLayer
//purpose  : 
//=======================================================================

Standard_Boolean OpenGl_LayerList::HasLayer 
  (const Standard_Integer theLayerId) const
{
  return myLayerIds.IsBound (theLayerId);
}

//=======================================================================
//function : RemoveLayer
//purpose  :
//=======================================================================

void OpenGl_LayerList::RemoveLayer (const Standard_Integer theLayerId)
{
  if (!HasLayer (theLayerId) || theLayerId == 0)
    return;

  Standard_Integer aRemovePos = myLayerIds.Find (theLayerId);
  
  // move all displayed structures to first layer
  const OpenGl_PriorityList& aList = myLayers.Value (aRemovePos);
  defaultLayer ().Append (aList);

  // remove layer
  myLayers.Remove (aRemovePos);
  myLayerIds.UnBind (theLayerId);

  // updated sequence indexes in map
  OpenGl_LayerSeqIds::Iterator aMapIt (myLayerIds);
  for ( ; aMapIt.More (); aMapIt.Next ())
  {
    Standard_Integer& aSeqIdx = aMapIt.ChangeValue ();
    if (aSeqIdx > aRemovePos)
      aSeqIdx--;
  }
}

//=======================================================================
//function : AddStructure
//purpose  :
//=======================================================================

void OpenGl_LayerList::AddStructure (const OpenGl_Structure *theStructure,
                                     const Standard_Integer  theLayerId,
                                     const Standard_Integer  thePriority)
{
  // add structure to associated layer,
  // if layer doesn't exists, display structure in default layer
  OpenGl_PriorityList& aList = !HasLayer (theLayerId) ? defaultLayer () :
    myLayers.ChangeValue (myLayerIds.Find (theLayerId));

  aList.Add (theStructure, thePriority);
  myNbStructures++;

  // Note: In ray-tracing mode we don't modify modification
  // state here. It is redundant, because the possible changes
  // will be handled in the loop for structures
}

//=======================================================================
//function : RemoveStructure
//purpose  : 
//=======================================================================

void OpenGl_LayerList::RemoveStructure (const OpenGl_Structure *theStructure,
                                        const Standard_Integer  theLayerId)
{
  Standard_Integer aSeqPos = !HasLayer (theLayerId) ?
    1 : myLayerIds.Find (theLayerId);
  
  OpenGl_PriorityList& aList = myLayers.ChangeValue (aSeqPos);

  // remove structure from associated list
  // if the structure is not found there,
  // scan through layers and remove it
  if (aList.Remove (theStructure) >= 0)
  {
    myNbStructures--;

#ifdef HAVE_OPENCL
    if (theStructure->IsRaytracable())
    {
      myModificationState++;
    }
#endif

    return;
  }
  
  // scan through layers and remove it
  Standard_Integer aSeqId = 1;
  OpenGl_SequenceOfLayers::Iterator anIts;
  for (anIts.Init (myLayers); anIts.More (); anIts.Next (), aSeqId++)
  {
    OpenGl_PriorityList& aScanList = anIts.ChangeValue ();
    if (aSeqPos == aSeqId)
      continue;
  
    if (aScanList.Remove (theStructure) >= 0)
    {
      myNbStructures--;

#ifdef HAVE_OPENCL
      if (theStructure->IsRaytracable())
      {
        myModificationState++;
      }
#endif

      return;
    }
  }
}

//=======================================================================
//function : ChangeLayer
//purpose  :
//=======================================================================

void OpenGl_LayerList::ChangeLayer (const OpenGl_Structure *theStructure,
                                    const Standard_Integer  theOldLayerId,
                                    const Standard_Integer  theNewLayerId)
{
  Standard_Integer aSeqPos = !HasLayer (theOldLayerId) ?
    1 : myLayerIds.Find (theOldLayerId);
  
  OpenGl_PriorityList& aList = myLayers.ChangeValue (aSeqPos);
  Standard_Integer aPriority;

  // take priority and remove structure from list found by <theOldLayerId>
  // if the structure is not found there, scan through all other layers
  if ((aPriority = aList.Remove (theStructure)) >= 0)
  {
    myNbStructures--;
    AddStructure (theStructure, theNewLayerId, aPriority);
  }
  else
  {
    // scan through layers and remove it
    Standard_Integer aSeqId = 1;
    OpenGl_SequenceOfLayers::Iterator anIts;
    for (anIts.Init (myLayers); anIts.More (); anIts.Next (), aSeqId++)
    {
      if (aSeqPos == aSeqId)
        continue;
  
      // try to remove structure and get priority value from this layer
      if ((aPriority = aList.Remove (theStructure)) >= 0)
      {
        myNbStructures--;
        AddStructure (theStructure, theNewLayerId, aPriority);
        break;
      }
    }
  }
}

//=======================================================================
//function : Render
//purpose  : Render this element
//=======================================================================

void OpenGl_LayerList::Render (const Handle(OpenGl_Workspace) &theWorkspace) const
{
  OpenGl_SequenceOfLayers::Iterator anIts;
  for(anIts.Init (myLayers); anIts.More (); anIts.Next ())
  {
    const OpenGl_PriorityList& aList = anIts.Value ();
    if (aList.NbStructures () > 0)
    {
      // separate depth buffers
      glClear (GL_DEPTH_BUFFER_BIT);

      // render priority list
      aList.Render (theWorkspace);
    }
  }
}
