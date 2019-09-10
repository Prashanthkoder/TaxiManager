#ifndef MANAGER_INCLUDED
#define MANAGER_INCLUDED

#include<stdio.h>
#include<fstream.h>

class cmpny employees {
  manager mngrs_list[20];
  driver drivers_list[400];
  class employee {
    int emp_id;
    char emp_name[30];
    char emp_lclty[20];
    long float emp_salary;
  }emps_list[80];
};
  
class manager {
  int mngr_id;
  char mngr_name[30];
  char mngr_cntrl_lclty[20];
  long float mngr_salary;
  driver own_drivers_list[20];
  public:
  void newmngrentry() {
    cin>>mngr_id;
    gets(mngr_name);
    gets(mngr_cntrl_lclty);
    cin>>mngr_salary;
  }
  void showmngrdetails(){
    cout<<"manager id:"<<mngr_id<<endl;
    cout<<"Name:";puts(mngr_name);
    cout<<"Control locality:";puts(mngr_cntrl_lclty);
    cout<<"Salary:"<<mngr_salary<<endl;
  }
};
#endif
