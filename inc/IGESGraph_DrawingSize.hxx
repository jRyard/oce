// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESGraph_DrawingSize_HeaderFile
#define _IGESGraph_DrawingSize_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESGraph_DrawingSize_HeaderFile
#include <Handle_IGESGraph_DrawingSize.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _IGESData_IGESEntity_HeaderFile
#include <IGESData_IGESEntity.hxx>
#endif


//! defines IGESDrawingSize, Type <406> Form <16> <br>
//!          in package IGESGraph <br>
class IGESGraph_DrawingSize : public IGESData_IGESEntity {

public:

  
  Standard_EXPORT   IGESGraph_DrawingSize();
  //! This method is used to set the fields of the class <br>
//!           DrawingSize <br>
//!      - nbProps : Number of property values (NP = 2) <br>
//!      - aXSize  : Extent of Drawing along positive XD axis <br>
//!      - aYSize  : Extent of Drawing along positive YD axis <br>
  Standard_EXPORT     void Init(const Standard_Integer nbProps,const Standard_Real aXSize,const Standard_Real aYSize) ;
  //! returns the number of property values in <me> (NP = 2) <br>
  Standard_EXPORT     Standard_Integer NbPropertyValues() const;
  //! returns the extent of Drawing along positive XD axis <br>
  Standard_EXPORT     Standard_Real XSize() const;
  //! returns the extent of Drawing along positive YD axis <br>
  Standard_EXPORT     Standard_Real YSize() const;




  DEFINE_STANDARD_RTTI(IGESGraph_DrawingSize)

protected:




private: 


Standard_Integer theNbPropertyValues;
Standard_Real theXSize;
Standard_Real theYSize;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
