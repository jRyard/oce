// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColStd_StdMapNodeOfMapOfTransient_HeaderFile
#define _TColStd_StdMapNodeOfMapOfTransient_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_TColStd_StdMapNodeOfMapOfTransient_HeaderFile
#include <Handle_TColStd_StdMapNodeOfMapOfTransient.hxx>
#endif

#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class Standard_Transient;
class TColStd_MapTransientHasher;
class TColStd_MapOfTransient;
class TColStd_MapIteratorOfMapOfTransient;



class TColStd_StdMapNodeOfMapOfTransient : public TCollection_MapNode {

public:

  
      TColStd_StdMapNodeOfMapOfTransient(const Handle(Standard_Transient)& K,const TCollection_MapNodePtr& n);
  
        Handle_Standard_Transient& Key() const;




  DEFINE_STANDARD_RTTI(TColStd_StdMapNodeOfMapOfTransient)

protected:




private: 


Handle_Standard_Transient myKey;


};

#define TheKey Handle_Standard_Transient
#define TheKey_hxx <Standard_Transient.hxx>
#define Hasher TColStd_MapTransientHasher
#define Hasher_hxx <TColStd_MapTransientHasher.hxx>
#define TCollection_StdMapNode TColStd_StdMapNodeOfMapOfTransient
#define TCollection_StdMapNode_hxx <TColStd_StdMapNodeOfMapOfTransient.hxx>
#define TCollection_MapIterator TColStd_MapIteratorOfMapOfTransient
#define TCollection_MapIterator_hxx <TColStd_MapIteratorOfMapOfTransient.hxx>
#define Handle_TCollection_StdMapNode Handle_TColStd_StdMapNodeOfMapOfTransient
#define TCollection_StdMapNode_Type_() TColStd_StdMapNodeOfMapOfTransient_Type_()
#define TCollection_Map TColStd_MapOfTransient
#define TCollection_Map_hxx <TColStd_MapOfTransient.hxx>

#include <TCollection_StdMapNode.lxx>

#undef TheKey
#undef TheKey_hxx
#undef Hasher
#undef Hasher_hxx
#undef TCollection_StdMapNode
#undef TCollection_StdMapNode_hxx
#undef TCollection_MapIterator
#undef TCollection_MapIterator_hxx
#undef Handle_TCollection_StdMapNode
#undef TCollection_StdMapNode_Type_
#undef TCollection_Map
#undef TCollection_Map_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
