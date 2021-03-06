// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepAlgo_EdgeConnector_HeaderFile
#define _BRepAlgo_EdgeConnector_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BRepAlgo_EdgeConnector_HeaderFile
#include <Handle_BRepAlgo_EdgeConnector.hxx>
#endif

#ifndef _TopTools_ListOfShape_HeaderFile
#include <TopTools_ListOfShape.hxx>
#endif
#ifndef _BRepAlgo_DataMapOfShapeBoolean_HeaderFile
#include <BRepAlgo_DataMapOfShapeBoolean.hxx>
#endif
#ifndef _TopOpeBRepBuild_BlockBuilder_HeaderFile
#include <TopOpeBRepBuild_BlockBuilder.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
class TopoDS_Edge;
class TopTools_ListOfShape;
class TopoDS_Shape;


//! Used by DSAccess to reconstruct an EdgeSet of connected edges. The result produced by <br>
//!           MakeBlock is a list of non-standard TopoDS_wire, <br>
//!          which  can present connexions of edge  of  order > 2 <br>
//!           in certain  vertex. The method  IsWire <br>
//!            indicates standard/non-standard character of  all wire produced. <br>
class BRepAlgo_EdgeConnector : public MMgt_TShared {

public:

  
  Standard_EXPORT   BRepAlgo_EdgeConnector();
  
  Standard_EXPORT     void Add(const TopoDS_Edge& e) ;
  
  Standard_EXPORT     void Add(TopTools_ListOfShape& LOEdge) ;
  
  Standard_EXPORT     void AddStart(const TopoDS_Shape& e) ;
  
  Standard_EXPORT     void AddStart(TopTools_ListOfShape& LOEdge) ;
  
  Standard_EXPORT     void ClearStartElement() ;
  //! returns a list of wire non standard <br>
  Standard_EXPORT     TopTools_ListOfShape& MakeBlock() ;
  
  Standard_EXPORT     void Done() ;
  //! NYI <br>//! returns true if proceeded  to MakeBlock() <br>
  Standard_EXPORT     Standard_Boolean IsDone() const;
  //! NYI <br>//! returns true if W is  a Wire standard. <br>
//!          W must belong  to the list returned  by MakeBlock. <br>
  Standard_EXPORT     Standard_Boolean IsWire(const TopoDS_Shape& W) ;




  DEFINE_STANDARD_RTTI(BRepAlgo_EdgeConnector)

protected:




private: 


TopTools_ListOfShape myListeOfEdge;
TopTools_ListOfShape myListeOfStartEdge;
BRepAlgo_DataMapOfShapeBoolean myResultMap;
TopTools_ListOfShape myResultList;
TopOpeBRepBuild_BlockBuilder myBlockB;
Standard_Boolean myIsDone;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
