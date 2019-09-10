#ifndef TIME_INCLUDED
#define TIME_INCLUDED
#include<time.h>
char* gettime()
{
  time_t tt;
  struct tm* ti;   
  time(&tt);        // initialize tt.
  ti = localtime(&tt); // get the current local time into ti
  return asctime(ti); // return in string form
}
#endif
