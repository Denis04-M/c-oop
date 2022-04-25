#include <iostream>
#include<vector> 
#include <map> 
using namespace std;
 
 class Employee{
     public:
     string name = "Tracy";
     string ssNumber = "5663484";
     void getDetaisl(){
         cout<<"Enter name";
         cin >> name;
         cout<<"Enter ssNumber";
         cin >> ssNumber;
     }

     virtual void print(){
         cout<<name<<"\n";
         cout<<ssNumber;
     }
 };

 class Hourly : public Employee{
     public:
     float h_wage;
     int hours;
     float wage;
     int weeklyWage(float hl_wage, int w_hours){
         h_wage = hl_wage;
         hours = w_hours;
         if (hours > 40){
             int over_time = hours - 40;
             wage = (40*h_wage) + (1.5*h_wage*over_time);
        }else{
            wage = hours*h_wage;}
        return 0;
         }

     void print(){
        cout<<"Name: "<<name<<"\n";
        cout<<"Social security number: "<<ssNumber<<"\n";
        cout<<"Hourly wage "<<h_wage<<"\n";
        cout<<"Total number of hours "<<hours<<"\n";
        cout<<"This weeks pay "<<wage;
    }
};

class Salaried : public Employee{
    public:
    float yearly_salary;
    float weekly_salary = yearly_salary/52;
    void print(float yearly_salary){
        cout<<name<<"\n";
        cout<<ssNumber<<"\n";
        cout<<yearly_salary<<"\n";
        cout<<weekly_salary;
    }
};

class Roster{
    public:
    map<string, string> employees;
    
    // adding an employee
    void addEmployee(string ssNumber, string name){
        // checking if the employee exist
        if (employees.find(ssNumber) != employees.end()) {
        std::cout << "Employee exist";
    }
    else {
        employees.insert(pair<string, string>(ssNumber, name));
    }
    }

    // deleting an employee
    void deleteEmployee(string ssNumber){
        employees.erase(ssNumber);
    }

    // printing all employees

    void print(){
        for( map<string,string>::iterator i=employees.begin(); i!=employees.end(); ++i){
            cout << (*i).first << ": " << (*i).second << endl;
            } 
    }
};
// Main() function: where the execution of program begins

int main()
{
    Hourly getEmployee;

    getEmployee.weeklyWage(15, 45);
    getEmployee.print();

}