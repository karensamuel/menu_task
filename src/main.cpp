#include <iostream>
#include "TerminalUi.h"
#include "ArrowInput2.h"
#include "Pages.h"
#define STATIC_OR_DYNAMIC  0 // where static = 0 and dynamic = 1
using namespace TerminalUI;
using namespace std;
int main()
{
    // choose app dynamic or static 
    mainScreen(STATIC_OR_DYNAMIC);

    return 0;
}