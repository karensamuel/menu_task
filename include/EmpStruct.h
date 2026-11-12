#ifndef EMPSTRUCT_H
#define EMPSTRUCT_H
struct EmpStruct
{
    char  name[30] ;
     int age;
     int salary;
     void addEmp(char * name , int age, int salary);
     void display ();
};
#endif
