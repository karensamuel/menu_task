#ifndef EMPL_CLASS_H
#define EMPL_CLASS_H
class EmployeeC{
    private:
    char  name[20] ;
     int age;
     int salary;
     public:
      void addEmp(char * name , int age, int salary);
void display ();
};
#endif