
#ifndef DYNAMICAPP_H
#define DYNAMICAPP_H

#include "EmpStruct.h"
void dynamicApp ();
void dynamicMainScreen( EmpStruct *&empArr,int &empCounter,int &maxEmp);
void drawDynamicScreen( int index );
void  displayDynamicEmployees( EmpStruct *&empArr,int &empCounter);
void  addEmployee (EmpStruct *&empArr, int &empCounter,int &maxEmp);
#endif