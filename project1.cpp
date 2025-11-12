// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
   int Totsecond,hr,min,remsecond,seconds;
   cout<<"enter the Totsecond:"<<endl;
   cin>>Totsecond;
   
   hr=Totsecond/3600;
   remsecond=Totsecond%3600;
   min= remsecond/60;
   seconds=remsecond%60;
   cout<<hr<<":"<<min<<":"<<seconds<<endl;


    return 0;
}