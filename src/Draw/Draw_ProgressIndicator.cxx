#include <Draw_ProgressIndicator.ixx>
#include <Draw_Interpretor.hxx>
#include <Draw.hxx>
#include <Message_ProgressScale.hxx>
#include <Message_Messenger.hxx>
#include <Message.hxx>
  
#include <time.h>
#include <stdio.h>

//=======================================================================
//function : Draw_ProgressIndicator
//purpose  : 
//=======================================================================

Draw_ProgressIndicator::Draw_ProgressIndicator(const Draw_Interpretor &di,
                                                   const Standard_Integer updateTime) :
       myTextMode ( DefaultTextMode() ),
       myGraphMode ( DefaultGraphMode() ),
       myDraw ( (Standard_Address)&di ),
       myShown ( Standard_False ),
       myBreak ( Standard_False ),
       myUpdateTime ( updateTime ),
       myLastUpdate ( 0 ), myStartTime ( 0 )
{
}

//=======================================================================
//function : Destroy
//purpose  : 
//=======================================================================

void Draw_ProgressIndicator::Destroy()
{
  Reset();
}

//=======================================================================
//function : Reset
//purpose  : 
//=======================================================================

void Draw_ProgressIndicator::Reset()
{
  Message_ProgressIndicator::Reset();
  if ( myShown ) {
    ((Draw_Interpretor*)myDraw)->Eval ( "destroy .xprogress" );
    myShown = Standard_False;
  }
  myBreak = Standard_False;
  myLastUpdate = myStartTime = 0;
}

//=======================================================================
//function : Show
//purpose  : 
//=======================================================================

Standard_Boolean Draw_ProgressIndicator::Show(const Standard_Boolean force)
{
  if ( ! myGraphMode && ! myTextMode ) return Standard_False;
  time_t aTimeT;
  time ( &aTimeT );
  Standard_Size aTime = (Standard_Size)aTimeT;
  if ( ! myStartTime ) myStartTime = aTime;
  if ( ! force && myUpdateTime >0 && aTime < myLastUpdate + myUpdateTime && GetPosition() < 1. )
    return Standard_False; // return if update interval has not elapsed
  myLastUpdate = aTime;
  
  // Prepare textual progress info
  char text[2048];
  Standard_Integer n = 0;
  n += sprintf ( &text[n], "Progress: %.0f%%", 100. * GetPosition() );
  for ( Standard_Integer i=GetNbScopes(); i >=1; i-- ) {
    const Message_ProgressScale &scale = GetScope ( i );
    if ( scale.GetName().IsNull() ) continue; // skip unnamed scopes
    // if scope has subscopes, print end of subscope as its current position
    Standard_Real locPos = ( i >1 ? GetScope ( i-1 ).GetLast() : GetPosition() );
    // print progress info differently for finite and infinite scopes
    if ( scale.GetInfinite() )
      n += sprintf ( &text[n], " %s: %.0f", scale.GetName()->ToCString(), 
                     scale.BaseToLocal ( locPos ) );
    else 
      n += sprintf ( &text[n], " %s: %.0f / %.0f", scale.GetName()->ToCString(), 
                     scale.BaseToLocal ( locPos ), scale.GetMax() );
  }

  // In addition, write elapsed/estimated/remaining time
  if ( GetPosition() > 0.01 ) {
    n += sprintf ( &text[n], "\nElapsed/estimated time: %ld/%.0f sec", 
                   (long)(aTime - myStartTime), ( aTime - myStartTime ) / GetPosition() );
  }
  
  // Show graphic progress bar
  if ( myGraphMode ) {
    if ( ! myShown ) {
      char command[1024];
      sprintf ( command, "toplevel .xprogress -height 100 -width 410;"
                         "wm title .xprogress \"Progress\";"
                         "set xprogress_stop 0;"
                         "canvas .xprogress.bar -width 402 -height 22;"
                         ".xprogress.bar create rectangle 2 2 2 21 -fill blue -tags progress;"
                         ".xprogress.bar create rectangle 2 2 2 21 -outline black -tags progress_next;"
                         "message .xprogress.text -width 400 -text \"Progress 0%%\";"
                         "button .xprogress.stop -text \"Break\" -relief groove -width 9 -command {XProgress -stop %ld};"
                         "pack .xprogress.bar .xprogress.text .xprogress.stop -side top;",
               (long)(void*)this );
      ((Draw_Interpretor*)myDraw)->Eval ( command );
      myShown = Standard_True;
    }
    char command[1024];
    Standard_Integer num = 0;
    num += sprintf ( &command[num], ".xprogress.bar coords progress 2 2 %.0f 21;", 
                  1+400*GetPosition() );
    num += sprintf ( &command[num], ".xprogress.bar coords progress_next 2 2 %.0f 21;", 
                  1+400*GetScope(1).GetLast() );
    num += sprintf ( &command[num], ".xprogress.text configure -text \"%s\";", text );
    num += sprintf ( &command[num], "update" );
    ((Draw_Interpretor*)myDraw)->Eval ( command );
  }

  // Print textual progress info
  if ( myTextMode )
    Message::DefaultMessenger()->Send (text, Message_Info);
  
  return Standard_True;
}
       
//=======================================================================
//function : UserBreak
//purpose  : 
//=======================================================================

Standard_Boolean Draw_ProgressIndicator::UserBreak()
{
  if ( StopIndicator() == (long)(void*)this ) {
//    cout << "Progress Indicator - User Break: " << StopIndicator() << ", " << (void*)this << endl;
    myBreak = Standard_True;
    ((Draw_Interpretor*)myDraw)->Eval ( "XProgress -stop 0" );
  }
  return myBreak;
}
       
//=======================================================================
//function : SetTextMode
//purpose  : Sets text output mode (on/off)
//=======================================================================

void Draw_ProgressIndicator::SetTextMode(const Standard_Boolean theTextMode)
{
  myTextMode = theTextMode;
}

//=======================================================================
//function : GetTextMode
//purpose  : Returns text output mode (on/off)
//=======================================================================

Standard_Boolean Draw_ProgressIndicator::GetTextMode() const
{
  return myTextMode;
}

//=======================================================================
//function : SetGraphMode
//purpose  : Sets graphical output mode (on/off)
//=======================================================================

void Draw_ProgressIndicator::SetGraphMode(const Standard_Boolean theGraphMode)
{
  myGraphMode = theGraphMode;
}

//=======================================================================
//function : GetGraphMode
//purpose  : Returns graphical output mode (on/off)
//=======================================================================

Standard_Boolean Draw_ProgressIndicator::GetGraphMode() const
{
  return myGraphMode;
}

//=======================================================================
//function : DefaultTextMode
//purpose  : 
//=======================================================================

Standard_Boolean &Draw_ProgressIndicator::DefaultTextMode () 
{
  static Standard_Boolean defTextMode = Standard_False;
  return defTextMode;
}
    
//=======================================================================
//function : DefaultGraphMode
//purpose  : 
//=======================================================================

Standard_Boolean &Draw_ProgressIndicator::DefaultGraphMode () 
{
  static Standard_Boolean defGraphMode = Standard_False;
  return defGraphMode;
}
    
//=======================================================================
//function : StopIndicator
//purpose  : 
//=======================================================================

Standard_Integer &Draw_ProgressIndicator::StopIndicator () 
{
  static Standard_Integer stopIndicator = 0;
  return stopIndicator;
}


