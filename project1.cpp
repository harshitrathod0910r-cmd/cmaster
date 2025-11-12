// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class timeconverter{
        public:
             int totsecond;
             int hr;
             int min;
             int remsecond;
             int seconds;
    
    void showdetail()
    {
         cout<<hr<<":"<<min<<":"<<seconds<<endl;
    }
             
             
};

int main() {
    
   timeconverter t1;
   cout<<"enter the Totsecond:"<<endl;
   cin>>t1.totsecond;
    
  
   t1.hr=t1.totsecond/3600;
   t1.remsecond=t1.totsecond%3600;
   t1.min=t1.remsecond/60;
   t1.seconds=t1.remsecond%60;
   t1.showdetail();
  


    return 0;
}