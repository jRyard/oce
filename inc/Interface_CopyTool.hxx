// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Interface_CopyTool_HeaderFile
#define _Interface_CopyTool_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_Interface_InterfaceModel_HeaderFile
#include <Handle_Interface_InterfaceModel.hxx>
#endif
#ifndef _Handle_Interface_CopyControl_HeaderFile
#include <Handle_Interface_CopyControl.hxx>
#endif
#ifndef _Handle_Interface_CopyMap_HeaderFile
#include <Handle_Interface_CopyMap.hxx>
#endif
#ifndef _Interface_BitMap_HeaderFile
#include <Interface_BitMap.hxx>
#endif
#ifndef _Interface_GeneralLib_HeaderFile
#include <Interface_GeneralLib.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TColStd_SequenceOfInteger_HeaderFile
#include <TColStd_SequenceOfInteger.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_Interface_GeneralModule_HeaderFile
#include <Handle_Interface_GeneralModule.hxx>
#endif
#ifndef _Handle_Interface_Protocol_HeaderFile
#include <Handle_Interface_Protocol.hxx>
#endif
class Interface_InterfaceModel;
class Interface_CopyControl;
class Interface_CopyMap;
class Standard_Transient;
class Interface_GeneralModule;
class Interface_InterfaceError;
class Interface_GeneralLib;
class Interface_Protocol;
class Interface_EntityIterator;


//! Performs Deep Copies of sets of Entities <br>
//!	         Allows to perform Copy of Interface Entities from a Model to <br>
//!           another one. Works by calling general services GetFromAnother <br>
//!           and GetImplied. <br>
//!           Uses a CopyMap to bind a unique Result to each Copied Entity <br>
//! <br>
//!           It is possible to command Copies of Entities (and those they <br>
//!           reference) by call to the General Service Library, or to <br>
//!           enforce results for transfer of some Entities (calling Bind) <br>
//! <br>
//!           A Same CopyTool can be used for several successive Copies from <br>
//!           the same Model : either by restarting from scratch (e.g. to <br>
//!           copy different parts of a starting Model to several Targets), <br>
//!           or incremental : in that case, it is possible to know what is <br>
//!           the content of the last increment (defined by last call to <br>
//!           ClearLastFlags  and queried by call to LastCopiedAfter) <br>
//! <br>
//!           Works in two times : first, create the list of copied Entities <br>
//!           second, pushes them to a target Model (manages also Model's <br>
//!           Header) or returns the Result as an Iterator, as desired <br>
//! <br>
//!           The core action (Copy) works by using ShallowCopy (method <br>
//!           attached to each class) and Copy from GeneralLib (itself using <br>
//!           dedicated tools). It can be redefined for specific actions. <br>
class Interface_CopyTool  {
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

  //! Creates a CopyTool adapted to work from a Model. Works <br>
//!           with a General Service Library, given as an argument <br>
  Standard_EXPORT   Interface_CopyTool(const Handle(Interface_InterfaceModel)& amodel,const Interface_GeneralLib& lib);
  //! Same as above, but Library is defined through a Protocol <br>
  Standard_EXPORT   Interface_CopyTool(const Handle(Interface_InterfaceModel)& amodel,const Handle(Interface_Protocol)& protocol);
  //! Same as above, but works with the Active Protocol <br>
  Standard_EXPORT   Interface_CopyTool(const Handle(Interface_InterfaceModel)& amodel);
  //! Returns the Model on which the CopyTool works <br>
  Standard_EXPORT     Handle_Interface_InterfaceModel Model() const;
  //! Changes the Map of Result for another one. This allows to work <br>
//!           with a more sophisticated Mapping Control than the Standard <br>
//!           one which is CopyMap (e.g. TransferProcess from Transfer) <br>
  Standard_EXPORT     void SetControl(const Handle(Interface_CopyControl)& othermap) ;
  //! Returns the object used for Control <br>
  Standard_EXPORT     Handle_Interface_CopyControl Control() const;
  //! Clears Transfer List. Gets Ready to begin another Transfer <br>
  Standard_EXPORT   virtual  void Clear() ;
  //! Creates the CounterPart of an Entity (by ShallowCopy), Binds <br>
//!           it, then Copies the content of the former Entity to the other <br>
//!           one (same Type), by call to the General Service Library <br>
//!           It may command the Copy of Referenced Entities <br>
//!           Then, its returns True. <br>
//! <br>
//!           If <mapped> is True, the Map is used to store the Result <br>
//!           Else, the Result is simply produced : it can be used to Copy <br>
//!           internal sub-parts of Entities, which are not intended to be <br>
//!           shared (Strings, Arrays, etc...) <br>
//!           If <errstat> is True, this means that the Entity is recorded <br>
//!           in the Model as Erroneous : in this case, the General Service <br>
//!           for Deep Copy is not called (this could be dangerous) : hence <br>
//!           the Counter-Part is produced but empty, it can be referenced. <br>
//! <br>
//!           This method does nothing and returns False if the Protocol <br>
//!           does not recognize <ent>. <br>
//!           It basically makes a Deep Copy without changing the Types. <br>
//!           It can be redefined for special uses. <br>
  Standard_EXPORT   virtual  Standard_Boolean Copy(const Handle(Standard_Transient)& entfrom,Handle(Standard_Transient)& entto,const Standard_Boolean mapped,const Standard_Boolean errstat) ;
  //! Transfers one Entity, if not yet bound to a result <br>
//!           Remark : For an Entity which is reported in the Starting Model, <br>
//!           the ReportEntity will also be copied with its Content if it <br>
//!           has one (at least ShallowCopy; Complete Copy if the Protocol <br>
//!           recognizes the Content : see method Copy) <br>
  Standard_EXPORT     Handle_Standard_Transient Transferred(const Handle(Standard_Transient)& ent) ;
  //! Defines a Result for the Transfer of a Starting object. <br>
//!           Used by method Transferred (which performs a normal Copy), <br>
//!           but can also be called to enforce a result : in the latter <br>
//!           case, the enforced result must be compatible with the other <br>
//!           Transfers which are performed <br>
  Standard_EXPORT     void Bind(const Handle(Standard_Transient)& ent,const Handle(Standard_Transient)& res) ;
  //! Search for the result of a Starting Object (i.e. an Entity) <br>
//!           Returns True  if a  Result is Bound (and fills "result") <br>
//!           Returns False if no result is Bound <br>
  Standard_EXPORT     Standard_Boolean Search(const Handle(Standard_Transient)& ent,Handle(Standard_Transient)& res) const;
  //! Clears LastFlags only. This allows to know what Entities are <br>
//!           copied after its call (see method LastCopiedAfter). It can be <br>
//!           used when copies are done by increments, which must be <br>
//!           distinghished. ClearLastFlags is also called by Clear. <br>
  Standard_EXPORT     void ClearLastFlags() ;
  //! Returns an copied Entity and its Result which were operated <br>
//!           after last call to ClearLastFlags. It returns the first <br>
//!           "Last Copied Entity" which Number follows <numfrom>, Zero if <br>
//!           none. It is used in a loop as follow : <br>
//!             Integer num = 0; <br>
//!             while ( (num = CopyTool.LastCopiedAfter(num,ent,res)) ) { <br>
//!               .. Process Starting <ent> and its Result <res> <br>
//!             } <br>
  Standard_EXPORT     Standard_Integer LastCopiedAfter(const Standard_Integer numfrom,Handle(Standard_Transient)& ent,Handle(Standard_Transient)& res) const;
  //! Transfers one Entity and records result into the Transfer List <br>
//!           Calls method Transferred <br>
  Standard_EXPORT     void TransferEntity(const Handle(Standard_Transient)& ent) ;
  //! Renews the Implied References. These References do not involve <br>
//!           Copying of referenced Entities. For such a Reference, if the <br>
//!           Entity which defines it AND the referenced Entity are both <br>
//!           copied, then this Reference is renewed. Else it is deleted in <br>
//!           the copied Entities. <br>
//!           Remark : this concerns only some specific references, such as <br>
//!           "back pointers". <br>
  Standard_EXPORT     void RenewImpliedRefs() ;
  //! Fills a Model with the result of the transfer (TransferList) <br>
//!           Commands copy of Header too, and calls RenewImpliedRefs <br>
  Standard_EXPORT     void FillModel(const Handle(Interface_InterfaceModel)& bmodel) ;
  //! Returns the complete list of copied Entities <br>
//!           If <withreports> is given True, the entities which were <br>
//!           reported in the Starting Model are replaced in the list <br>
//!           by the copied ReportEntities <br>
  Standard_EXPORT     Interface_EntityIterator CompleteResult(const Standard_Boolean withreports = Standard_False) const;
  //! Returns the list of Root copied Entities (those which were <br>
//!           asked for copy by the user of CopyTool, not by copying <br>
//!           another Entity) <br>
  Standard_EXPORT     Interface_EntityIterator RootResult(const Standard_Boolean withreports = Standard_False) const;
  
  Standard_EXPORT   virtual  void Destroy() ;
Standard_EXPORT virtual ~Interface_CopyTool() { Destroy(); }





protected:

  //! Creates a new void instance (just created) of the same class <br>
//!           as <entfrom>. Uses the general service GeneralModule:NewVoid <br>
//!           Returns True if OK (Recognize has succeeded), False else <br>
//!           (in such a case, the standard method ShallowCopy is called <br>
//!           to produce <ento> from <entfrom> : hence it is not void) <br>
//! <br>
//!           No mapping is managed by this method <br>
  Standard_EXPORT   virtual  Standard_Boolean NewVoid(const Handle(Standard_Transient)& entfrom,Handle(Standard_Transient)& entto) ;


Interface_GeneralLib thelib;


private:

  //! Renews the Implied References of one already Copied Entity <br>
  Standard_EXPORT   virtual  void Implied(const Handle(Standard_Transient)& entfrom,const Handle(Standard_Transient)& entto) ;


Handle_Interface_InterfaceModel themod;
Handle_Interface_CopyControl themap;
Handle_Interface_CopyMap therep;
Interface_BitMap thelst;
Standard_Integer thelev;
TColStd_SequenceOfInteger therts;
Standard_Boolean theimp;
Handle_Standard_Transient theent;
Handle_Interface_GeneralModule themdu;
Standard_Integer theCN;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
