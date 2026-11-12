#include <iostream>
#include "TerminalUi.h"
#include "ArrowInput2.h"
#include "EmplClass.h"
#include "StaticApp.h"
using namespace std;
using namespace TerminalUI;

void staticApp (){
 EmployeeC empArr [30];
 int empCounter =0;
 int maxEmp=0;
  staticMainScreen(empArr,empCounter,maxEmp);




}
void addEmployee( EmployeeC empArr[], int &empCounter,int &maxEmp){
    char ans='N';
    char  name[30];
    int age;
    int salary;
    resetScreen();
    if(empCounter == 0){
        cout<< "how many emp do you have?"<<endl;
       
        cin>>maxEmp;
        while (maxEmp<1 || maxEmp>30){
            cout << "wrong input try again :\n";
              cin.clear();
    cin.ignore(1000, '\n');
            cin >>maxEmp;

        }

    }
    while(empCounter<maxEmp){
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
            empCounter ++;
             cin.ignore(1000, '\n');
        }else if (ans == 'n'|| ans == 'N'){
            resetScreen();
            return;
        }else{
            cout<<"Couldnt understand input please try again ...";
        }


    }
    cout << "size is full ";
   

}
void staticMainScreen( EmployeeC empArr[], int &empCounter,int &maxEmp){
      int  index = 0;
   drawStaticScreen(index);
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
             cout<<" display is enterrred ";
                addEmployee(empArr,empCounter,maxEmp);
                drawStaticScreen(index);
            }else if(index == 1){ //display all employee
                cout<<" display is enterrred ";
               displayEmployees(empArr,empCounter);
               drawStaticScreen(index);
            }
        }
         //std::cout<<"Byte 1 :: "<<byte1<<std::endl;
        // If the key is the beginning of an arrow-key escape sequence
        if (byte1 == '\033') {
            // Skip the second character '['
           #ifdef _WIN32
            #else
                byte2=getch_all();
            #endif
     #ifdef _WIN32
             byte3=getch_all();
          
          
 switch (byte3) {
            case 72: byte3 = 'A'; break;
            case 80: byte3 = 'B'; break;
            case 77: byte3 = 'C'; break;
            case 75: byte3 = 'D'; break;
            case 71: byte3 = 'H'; break;
            case 79: byte3 = 'F'; break;
                    
        }
    
          
        }
            #else
                byte3=getch_all();
            #endif
            // The third character determines the arrow direction
            //std::cout<<"Byte 3 :: "<<byte3<<std::endl;
       
           
            switch (byte3) {
                case 'A':
                    //std::printf("↑ Up Arrow\n");
                    //move up
                    if(index != 0){
                      
                        --index;
                        drawStaticScreen(index);
                       
                    }
                    break;

                case 'B':
                    //std::printf("↓ Down Arrow\n");
                    if(index != 2){
                      
                       
                        ++index;
                        drawStaticScreen(index);
                        
                    }
                    break;
                case 'H':
                    index = 0;
                    drawStaticScreen(index);
                    break;
                case 'F':
                      index = 2;
                    drawStaticScreen(index);
                    break;

                
            }
    }
    while(index != 2 || byte1 != '\n');  
}
void drawStaticScreen( int index ){
    int x =25;
    int y = 6;

    resetScreen();
    drawText("menu",x,y,Color::BLUE);
    drawText((index ==0)? "-> NEW" :"NEW",x,y+2,(index ==0)? Color::YELLOW :Color::BLUE);
    drawText((index ==1)? "-> DISPLAY" :"DISPLAY",x,y+4,(index ==1)? Color::YELLOW :Color::BLUE);
    drawText((index ==2)? "-> QUIT" :"QUIT",x,y+6,(index ==2)? Color::YELLOW :Color::BLUE);
  
   hideCurser();
    




}
void displayEmployees(EmployeeC empArr[], int &empCounter){
    
    char byte1='b';
    do{
         resetScreen();
    for(int i = 0 ;i<empCounter; i++){
        empArr[i].display();
    }
    cout << "press Q or q to leave\n";
             byte1= getch_all();

}while (byte1 !='q' && byte1 != 'Q');


}