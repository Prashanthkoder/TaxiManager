#ifndef LOCATIONS_INCLUDED
#define LOCATIONS_INCLUDED
#include<math.h>
#include<stdio.h>
#include<iostream.h>
struct Location
{
  char* locationName;
  int x, y;
  void setLoc(char* LocName, int x2, int y2)
  {
      locationName = LocName;
      x= x2;
      y= y2;
  }
void retloc()
{return locationname;
}
};
typedef Location Loc;
//typedef  Location cLoc;
Loc ORIGIN, locs[15];
void init_locs()
{
    ORIGIN.setLoc("ORIGIN", 0, 0);
    locs[0].setLoc("Airport", 0, 0);
    locs[1].setLoc("Alandur", 30, 25);
    locs[2].setLoc("Ashok Nagar", 30, 55);
    locs[3].setLoc("Vadapalani", 30, 70);
    locs[4].setLoc("CMBT", 25, 85);
    locs[5].setLoc("Thirumangalam", 20, 100);
    locs[6].setLoc("Anna nagar",40 , 100);  
    locs[7].setLoc("Kilpauk", 65, 80);
    locs[8].setLoc("Egmore", 90, 90); 
    locs[9].setLoc("Chennai Central", 100, 100);
    
}
double dist(Loc l1, Loc l2)
{
  return sqrt( pow(l1.x-l2.x,2) + pow(l1.y-l2.y, 2));
}
void displocs()
{int lch;
cout<<"Choose from the following locations";
for(int i=0;i<10;i++)
{cout<<i+1<<". "<<locs[i].retloc()<<endl;}
cin>>lch;
if(lch>10||lch<1)
{cout<<"your choice is invalid. Our service is restricted to the above locations only";
return;
}
else retloc2(lch);
}
Loc retloc2(int ch)
{
return loc[ch-1];
}
void getLoc(Loc& l1)
{
  gets(l1.locationName);
  cin>>l1.x>>l1.y;
}
#endif
