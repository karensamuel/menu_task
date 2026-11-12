#include "DynamicApp.h"
#include "EmpStruct.h"
#include "TerminalUi.h"
#include <iostream>
#include "ArrowInput2.h"
using namespace TerminalUI;
using namespace std;
void dynamicApp (){
     int maxEmp=2;
 EmpStruct* empArr = new EmpStruct[maxEmp];
 int empCounter =0;

  dynamicMainScreen(empArr,empCounter,maxEmp);
  delete[] empArr;
}
void dynamicMainScreen( EmpStruct *&empArr,int &empCounter,int &maxEmp){
        int  index = 0;
   drawDynamicScreen(index);
 int byte1= 'q';
  int  byte3= 'q';
    do{
          byte1= getch_all();
            #ifdef _WIN32
             if (byte1 == 224)
                  byte1= '\033';
            if (byte1 == '\r') byte1= '\n';
            #endif

      
        if(byte1 == '\n' ){
           if (index ==0){ // add new employee 
            
                addEmployee(empArr,empCounter,maxEmp);
                drawDynamicScreen(index);
            }else if(index == 1){ //display all employee
            
               displayDynamicEmployees(empArr,empCounter);
               cout << "Returned from display\n";

               drawDynamicScreen(index);
            }
        }
         //std::cout<<"Byte 1 :: "<<byte1<<std::endl;
        // If the key is the beginning of an arrow-key escape sequence
        if (byte1 == '\033') {
            // Skip the second character '['
           #ifdef _WIN32
              byte3=getch_all();
                     
 switch (byte3) {
            case 72: byte3 = 'A'; break;
            case 80: byte3 = 'B'; break;
            case 77: byte3 = 'C'; break;
            case 75: byte3 = 'D'; break;
            case 71: byte3 = 'H'; break;
            case 79: byte3 = 'F'; break;
             default: byte3 = 0; break;
                    
        }
            #else
                byte2=getch_all();
                byte3=getch_all();
            #endif
               switch (byte3) {
                case 'A':
                    //std::printf("↑ Up Arrow\n");
                    //move up
                    if(index != 0){
                      
                        --index;
                        drawDynamicScreen(index);
                       
                    }
                    break;

                case 'B':
                    //std::printf("↓ Down Arrow\n");
                    if(index != 2){
                      
                       
                        ++index;
                        drawDynamicScreen(index);
                        
                    }
                    break;
                case 'H':
                    index = 0;
                    drawDynamicScreen(index);
                    break;
                case 'F':
                      index = 2;
                    drawDynamicScreen(index);
                    break;

                
            }
   
    
   
    }
          
              
          
            // The third character determines the arrow direction
            //std::cout<<"Byte 3 :: "<<byte3<<std::endl;
       
           
          }
    while(index != 2 || byte1 != '\n');  
}
void drawDynamicScreen( int index ){

    int x =25;
    int y = 6;

    resetScreen();
    drawText("menu",x,y,Color::BLUE);
    drawText((index ==0)? "-> NEW" :"NEW",x,y+2,(index ==0)? Color::YELLOW :Color::BLUE);
    drawText((index ==1)? "-> DISPLAY" :"DISPLAY",x,y+4,(index ==1)? Color::YELLOW :Color::BLUE);
    drawText((index ==2)? "-> QUIT" :"QUIT",x,y+6,(index ==2)? Color::YELLOW :Color::BLUE);
  
   hideCurser();
    




}
void  displayDynamicEmployees( EmpStruct *&empArr,int &empCounter){
     int byte1='b';
    do{
         resetScreen();
    for(int i = 0 ;i<empCounter; i++){
        empArr[i].display();
    }
    cout << "press Q or q to leave\n";
             byte1= getch_all();

}while (byte1 !='q' && byte1 != 'Q');
}
void  addEmployee (EmpStruct *&empArr, int &empCounter,int &maxEmp){
     char ans='N';
    char  name[30];
    int age;
    int salary;
    resetScreen();
   int byte1='b';
    while(byte1 !='q' && byte1 != 'Q'){
        if(empCounter == maxEmp){
           
            int newSize = maxEmp*2;
            EmpStruct *newArr = new EmpStruct[newSize];
            for(int i = 0 ; i < empCounter; i++){
                newArr[i] = empArr[i];
            }
            delete[] empArr;
            maxEmp = newSize;
            empArr = newArr;
        }
        cout<< " do you want to add an employee?(Y/N)";
        cin>>ans;
        if(ans == 'y'|| ans == 'Y'){
            cout<< " add name:";
            cin>> name;
             cout<< " add age:";
            cin>> age;
             cout<< " add salary:";
            cin>> salary;
           
            empArr[empCounter].addEmp(name, age, salary);
            cout << "Employee added successfully!" << endl;
            empCounter ++;
             cin.ignore(1000, '\n');
        }else if (ans == 'n'|| ans == 'N'){
            resetScreen();
            return;
        }else{
            cout<<"Couldnt understand input please try again ...";
        }

 //byte1= getch_all();
    }
    

}