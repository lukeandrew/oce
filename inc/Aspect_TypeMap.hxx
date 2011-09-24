// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Aspect_TypeMap_HeaderFile
#define _Aspect_TypeMap_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Aspect_TypeMap_HeaderFile
#include <Handle_Aspect_TypeMap.hxx>
#endif

#ifndef _Aspect_SequenceOfTypeMapEntry_HeaderFile
#include <Aspect_SequenceOfTypeMapEntry.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Aspect_BadAccess;
class Aspect_TypeMapEntry;
class Aspect_LineStyle;


//! This class defines a TypeMap object. <br>
class Aspect_TypeMap : public MMgt_TShared {

public:

  
  Standard_EXPORT   Aspect_TypeMap();
  //! Adds an entry in the type map <me>. <br>
//!  Warning: Raises BadAccess if TypeMap size is exceeded. <br>
  Standard_EXPORT     void AddEntry(const Aspect_TypeMapEntry& AnEntry) ;
  //! Search an identical type style entry in the type map <me> <br>
//! and returns the TypeMapEntry Index if exist. <br>
//! Or add a new entry and returns the computed TypeMapEntry index used. <br>
  Standard_EXPORT     Standard_Integer AddEntry(const Aspect_LineStyle& aStyle) ;
  //! Returns the Allocated typemap Size <br>
  Standard_EXPORT     Standard_Integer Size() const;
  //! Returns the TypeMapEntry.Index of the TypeMap <br>
//!          at rank <aTypemapIndex> . <br>
  Standard_EXPORT     Standard_Integer Index(const Standard_Integer aTypemapIndex) const;
  
  Standard_EXPORT     void Dump() const;
  //! Returns the Type map entry with the index <AnIndex>. <br>
//!  Warning: Raises BadAccess if the index less than 1 or <br>
//!	    greater than Size. <br>
  Standard_EXPORT    const Aspect_TypeMapEntry& Entry(const Standard_Integer AnIndex) const;




  DEFINE_STANDARD_RTTI(Aspect_TypeMap)

protected:


Aspect_SequenceOfTypeMapEntry mydata;


private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif