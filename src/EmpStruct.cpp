#include <iostream>
using namespace std;
#include "EmpStruct.h"

   void EmpStruct:: addEmp(char * name , int age, int salary){
        
        int index =0;
        while ( name[index] != '\0'&& index < 30 ){
          this->name[index]= name[index];
          index ++;

        }
           this->name[index] = '\0';
        this->age = age;
        this->salary = salary;
     }
     void EmpStruct::display (){
        std::cout << "name:" << name << " age:" << age << " salary:" << salary << std::endl;
     }

