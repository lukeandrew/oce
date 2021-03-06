// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColStd_QueueNodeOfQueueOfInteger_HeaderFile
#define _TColStd_QueueNodeOfQueueOfInteger_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_TColStd_QueueNodeOfQueueOfInteger_HeaderFile
#include <Handle_TColStd_QueueNodeOfQueueOfInteger.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class TColStd_QueueOfInteger;



class TColStd_QueueNodeOfQueueOfInteger : public TCollection_MapNode {

public:

  
      TColStd_QueueNodeOfQueueOfInteger(const Standard_Integer& I,const TCollection_MapNodePtr& n);
  
        Standard_Integer& Value() const;




  DEFINE_STANDARD_RTTI(TColStd_QueueNodeOfQueueOfInteger)

protected:




private: 


Standard_Integer myValue;


};

#define Item Standard_Integer
#define Item_hxx <Standard_Integer.hxx>
#define TCollection_QueueNode TColStd_QueueNodeOfQueueOfInteger
#define TCollection_QueueNode_hxx <TColStd_QueueNodeOfQueueOfInteger.hxx>
#define Handle_TCollection_QueueNode Handle_TColStd_QueueNodeOfQueueOfInteger
#define TCollection_QueueNode_Type_() TColStd_QueueNodeOfQueueOfInteger_Type_()
#define TCollection_Queue TColStd_QueueOfInteger
#define TCollection_Queue_hxx <TColStd_QueueOfInteger.hxx>

#include <TCollection_QueueNode.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_QueueNode
#undef TCollection_QueueNode_hxx
#undef Handle_TCollection_QueueNode
#undef TCollection_QueueNode_Type_
#undef TCollection_Queue
#undef TCollection_Queue_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
