#include "Pages.h"
#include "TerminalUi.h"
#include "ArrowInput2.h"
#include "StaticApp.h"
#include "DynamicApp.h"
using namespace TerminalUI;
void  mainScreen(bool staticOrDynamic){
         // (staticOrDynamic==0)?staticApp():dynamicApp();
staticApp();
}
