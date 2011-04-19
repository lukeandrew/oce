// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Graphic3d_SequenceNodeOfSequenceOfStructure_HeaderFile
#define _Graphic3d_SequenceNodeOfSequenceOfStructure_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Graphic3d_SequenceNodeOfSequenceOfStructure_HeaderFile
#include <Handle_Graphic3d_SequenceNodeOfSequenceOfStructure.hxx>
#endif

#ifndef _Handle_Graphic3d_Structure_HeaderFile
#include <Handle_Graphic3d_Structure.hxx>
#endif
#ifndef _TCollection_SeqNode_HeaderFile
#include <TCollection_SeqNode.hxx>
#endif
#ifndef _TCollection_SeqNodePtr_HeaderFile
#include <TCollection_SeqNodePtr.hxx>
#endif
class Graphic3d_Structure;
class Graphic3d_SequenceOfStructure;



class Graphic3d_SequenceNodeOfSequenceOfStructure : public TCollection_SeqNode {

public:

  
      Graphic3d_SequenceNodeOfSequenceOfStructure(const Handle(Graphic3d_Structure)& I,const TCollection_SeqNodePtr& n,const TCollection_SeqNodePtr& p);
  
        Handle_Graphic3d_Structure& Value() const;




  DEFINE_STANDARD_RTTI(Graphic3d_SequenceNodeOfSequenceOfStructure)

protected:




private: 


Handle_Graphic3d_Structure myValue;


};

#define SeqItem Handle_Graphic3d_Structure
#define SeqItem_hxx <Graphic3d_Structure.hxx>
#define TCollection_SequenceNode Graphic3d_SequenceNodeOfSequenceOfStructure
#define TCollection_SequenceNode_hxx <Graphic3d_SequenceNodeOfSequenceOfStructure.hxx>
#define Handle_TCollection_SequenceNode Handle_Graphic3d_SequenceNodeOfSequenceOfStructure
#define TCollection_SequenceNode_Type_() Graphic3d_SequenceNodeOfSequenceOfStructure_Type_()
#define TCollection_Sequence Graphic3d_SequenceOfStructure
#define TCollection_Sequence_hxx <Graphic3d_SequenceOfStructure.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif