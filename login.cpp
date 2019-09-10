#include<fstream.h>
#include "customtime.h"
class Session
{
    char* stime, etime;
    char* user;
    int prof; // 1-customer 2-manager
    int isopen; // 0 if session ended 1 if session running
public:
    Session(char* u, int p)
    {
        user = u;
        prof = p;
        stime = gettime();
        isopen = 1;
    }
    int endSession()
    {
        isopen = 0;
        etime = gettime();
        fstream logger("slog.txt", ios::in|ios::out|ios::app);
        logger<<stime<<" to "<<etime<<" username: "<<user<<" prof: "<<prof<<endl;
        logger.close();
        return 1; // session ended successfully
    }

}currentSession;

Session nullSession("", -1);

Session validateUser(char* user, char* pass, int prof)
{
    fstream f;
    if(prof == 1)
    {   f.open("Customer.dat", ios::in|ios::out|ios::binary|ios::ate);}
    if(prof == 2)
    {   f.open("Manager.dat", ios::in|ios::out|ios::binary|ios::ate);}
    f.seekg(0, ios::beg);
    Customer c;
    int flag = 0;
    while(f.read((char*)&c, sizeof(c))
        if(c.getUser()==user&&c.getPass()==pass)
            flag=1;
    if(flag==0) return nullSession; // incorrect user/pass
    return Session(user, prof);
}

int login()
{
   re:
    cout<<" Login as a 1.customer\n2.manager\n3.Cancel"<<endl;
    int ch;
    cin>>ch;
    if(!(ch==1||ch==2)) return -1;
    cout<<"Please enter your Username and password "<<endl;
    char* user, pass
    gets(user);
    gets(pass);
    currentSession = validateUser(user, pass, ch);
    if(currentSession==nullSession){cout<<"Incorrect username or password. Please try again "<<endl;goto re;}
}
int logout()
{
    if(currentSession==nullSession||currentSession.isOpen()==0)
        return -1;
    currentSession.endSession();
    cout<<"Bye. See you later"<<endl;
}
