// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Geom2dGcc_MyC2d2TanOn_HeaderFile
#define _Geom2dGcc_MyC2d2TanOn_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _gp_Circ2d_HeaderFile
#include <gp_Circ2d.hxx>
#endif
#ifndef _GccEnt_Position_HeaderFile
#include <GccEnt_Position.hxx>
#endif
#ifndef _gp_Pnt2d_HeaderFile
#include <gp_Pnt2d.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class StdFail_NotDone;
class Geom2dAdaptor_Curve;
class Geom2dGcc_CurveTool;
class Geom2dGcc_MyQCurve;
class Geom2dGcc_FuncTCuCuOnCuOfMyC2d2TanOn;
class GccEnt_QualifiedCirc;
class gp_Lin2d;
class GccEnt_QualifiedLin;
class gp_Pnt2d;
class gp_Circ2d;



class Geom2dGcc_MyC2d2TanOn  {
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

  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const GccEnt_QualifiedCirc& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const gp_Lin2d& OnLine,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Param3,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const GccEnt_QualifiedLin& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const gp_Lin2d& OnLine,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Param3,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const Geom2dGcc_MyQCurve& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const gp_Lin2d& OnLine,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Param3,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const Geom2dGcc_MyQCurve& Qualified1,const gp_Pnt2d& Point2,const gp_Lin2d& OnLine,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const GccEnt_QualifiedCirc& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const gp_Circ2d& OnCirc,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Param3,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const GccEnt_QualifiedLin& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const gp_Circ2d& OnCirc,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Param3,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const Geom2dGcc_MyQCurve& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const gp_Circ2d& OnCirc,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Param3,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const Geom2dGcc_MyQCurve& Qualified1,const gp_Pnt2d& Point2,const gp_Circ2d& OnCirc,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const GccEnt_QualifiedCirc& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const Geom2dAdaptor_Curve& OnCurv,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real ParamOn,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const GccEnt_QualifiedLin& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const Geom2dAdaptor_Curve& OnCurve,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real ParamOn,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const Geom2dGcc_MyQCurve& Qualified1,const gp_Pnt2d& Point2,const Geom2dAdaptor_Curve& OnCurve,const Standard_Real Param1,const Standard_Real ParamOn,const Standard_Real Tolerance);
  
  Standard_EXPORT   Geom2dGcc_MyC2d2TanOn(const Geom2dGcc_MyQCurve& Qualified1,const Geom2dGcc_MyQCurve& Qualified2,const Geom2dAdaptor_Curve& OnCurve,const Standard_Real Param1,const Standard_Real Param2,const Standard_Real ParamOn,const Standard_Real Tolerance);
  
  Standard_EXPORT     Standard_Boolean IsDone() const;
  
  Standard_EXPORT     gp_Circ2d ThisSolution() const;
  
  Standard_EXPORT     void WhichQualifier(GccEnt_Position& Qualif1,GccEnt_Position& Qualif2) const;
  
  Standard_EXPORT     void Tangency1(Standard_Real& ParSol,Standard_Real& ParArg,gp_Pnt2d& PntSol) const;
  
  Standard_EXPORT     void Tangency2(Standard_Real& ParSol,Standard_Real& ParArg,gp_Pnt2d& PntSol) const;
  
  Standard_EXPORT     void CenterOn3(Standard_Real& ParArg,gp_Pnt2d& PntSol) const;
  
  Standard_EXPORT     Standard_Boolean IsTheSame1() const;
  
  Standard_EXPORT     Standard_Boolean IsTheSame2() const;





protected:





private:



Standard_Boolean WellDone;
gp_Circ2d cirsol;
GccEnt_Position qualifier1;
GccEnt_Position qualifier2;
Standard_Boolean TheSame1;
Standard_Boolean TheSame2;
gp_Pnt2d pnttg1sol;
gp_Pnt2d pnttg2sol;
gp_Pnt2d pntcen;
Standard_Real par1sol;
Standard_Real par2sol;
Standard_Real pararg1;
Standard_Real pararg2;
Standard_Real parcen3;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
