// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepAlgo_Fuse_HeaderFile
#define _BRepAlgo_Fuse_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BRepAlgo_BooleanOperation_HeaderFile
#include <BRepAlgo_BooleanOperation.hxx>
#endif
class TopoDS_Shape;


//! Describes functions for performing a topological <br>
//! fusion operation (Boolean union). <br>
//! A Fuse object provides the framework for: <br>
//! - defining the construction of a fused shape, <br>
//! - implementing the construction algorithm, and <br>
//! - consulting the result. <br>
class BRepAlgo_Fuse  : public BRepAlgo_BooleanOperation {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  //! Fuse S1 and S2. <br>
  Standard_EXPORT   BRepAlgo_Fuse(const TopoDS_Shape& S1,const TopoDS_Shape& S2);





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
