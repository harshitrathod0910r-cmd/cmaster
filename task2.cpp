#include<iostream>
using namespace std;

class bankacount
{
    private:
            int accountno;
            int balance;
            string ownerename;
    public:

        void setacno(int a) {accountno=a;}
        void setbalance() 
        {
           cout<<"enter the balance:"<<endl;
           cin>>balance;
        }
        void setownername(string o){ownerename=o;}

        int getacno() {return accountno;}
       
        string getownername() { return ownerename;}

        void debit(int x)
        {
            balance=balance+x;
            cout<<"debit amount is:"<<x<<endl;
        }

           void credit(int x)
        {
            balance=balance-x;
            cout<<"credit amount is:"<<x<<endl;
        }
         int getbalance() {return balance; }
    };

    int main()
    {
        bankacount ac;
        ac.setacno(1234567890);
        ac.setownername("vijay");
        ac.setbalance();

        cout<<"account no is:"<<ac.getacno()<<endl;
        cout<<"owner name is:"<<ac.getownername()<<endl;
       

        ac.debit(200);
        ac.credit(50);

         cout<<"total Amount is:"<<ac.getbalance()<<endl;

        return 0;
    }