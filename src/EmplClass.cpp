#include <iostream>
#include "EmplClass.h"
using namespace std;
void EmployeeC::display() {
    cout << "name:" << name << " age:" << age << " salary:" << salary << endl;
}

void EmployeeC::addEmp(char* name, int age, int salary) {
    int index =0;
    while ( name[index] != '\0'&& index < 20 ){
      this->name[index]= name[index];
      index ++;

    }
       this->name[index] = '\0';
    this->age = age;
    this->salary = salary;
}