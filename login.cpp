#include<fstream.h>
#include "customtime.h"
class Session
{
    char* stime, *etime;
   // char* user;
    Customer c;
    public:
    int isOpen; // 0 if session ended 1 if session running
public:
    Session(){}
    Session(Customer c2)
    {
        c = c2;
        stime = gettime();
        isOpen = 1;
    }
    int endSession()
    {
        isOpen = 0;
        etime = gettime();
        fstream logger("slog.txt", ios::in|ios::out|ios::app);
        int i=0;
        logger<<stime<<" to "<<etime<<" username: "<<c.getUser()<<endl;
        logger.close();
        return 1; // session ended successfully
    }
    Customer retCustomer(){return c;}
    int isNull(){return (c.isValid()==-1)?1:0;}

};

Session nullSession(Customer(-1));

Session validateUser(char* user, char* pass)
{
    fstream f;
    f.open("Customer.dat", ios::in|ios::out|ios::binary|ios::ate);
    f.seekg(0, ios::beg);
    Customer c;
    int flag = 0;
    while(f.read((char*)&c, sizeof(c)))
        if(c.getUser()==user&&c.getPass()==pass)
            flag=1;
    if(flag==0) {f.close();return Session(Customer(-1));} // incorrect user/pass
    f.close();
    return Session(c);
}

Session login(char* user)
{
re:
    cout<<"1.Login 2.Go Back"<<endl;
    int ch;
    cin>>ch;
    if(ch==2)return Customer(-1);
    cout<<"Please enter your password "<<endl;
    char* pass;
    gets(pass);
    Session currentSession = validateUser(user, pass);
    if(currentSession.isNull())cout<<"Incorrect username or password. Please try again "<<endl;
        goto re;
    return currentSession;

}
int logout(Session currentSession)
{
    if(currentSession.isNull()||currentSession.isOpen==0)
        return 0;
    currentSession.endSession();
    cout<<"Bye. See you later"<<endl;
    return 1;
}
