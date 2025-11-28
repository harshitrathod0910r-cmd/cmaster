
#include <iostream>
using namespace std;

class trainrecords
{
private:
    int train_no;
    string train_name;
    string train_source;
    string train_destination;
    string train_time;

    static int train_count;

public:
    static void print()
    {
        cout << "total train:" << train_count;
    }

    trainrecords()
    {
        train_no = 0;
        train_name = "none";
        train_source = "none";
        train_destination = "none";
        train_time = "none";
    }

    trainrecords(int i, string n, string s, string d, string t)
    {
        train_no = i;
        train_name = n;
        train_source = s;
        train_destination = d;
        train_time = t;
        train_count++;
        
    }

  
    void setdetail(int i, string n, string s, string d, string t)
    {
        train_no = i;
        train_name = n;
        train_source = s;
        train_destination = d;
        train_time = t;
        train_count++;
    }

    void showtraindetails()
    {

        cout << " train_name:" << train_name << endl;
        cout << " train_source:" << train_source << endl;
        cout << " train_destination" << train_destination << endl;
        cout << " train_time" << train_time << endl;
        cout << "-----------------------------------------" << endl;
        
    }

    int getno()
    {
        return train_no;
    }

    void inputtraindeatails()
    {
        cout << "enter train no:" << endl;
        cin >> train_no;
        cout << "enter train name:" << endl;
        cin >> train_name;
        cout << "enter train source:" << endl;
        cin >> train_source;
        cout << "enter train destination:" << endl;
        cin >> train_destination;
        cout << "enter train time:" << endl;
        cin >> train_time;
    }

    void display()
    {
        cout << " train_no:" << train_no << endl;
        cout << " train_name:" << train_name << endl;
        cout << " train_source:" << train_source << endl;
        cout << " train_destination" << train_destination << endl;
        cout << " train_time" << train_time << endl;
        cout << "-----------------------------------------";
    }
};
int trainrecords::train_count = 0;
int main()
{
    int searchno, flag, choiceno;
    trainrecords t;
    cout << "---Railway Resevation System---" << endl;
    cout << "1.Add new train record" << endl;
    cout << "2.display all train record" << endl;
    cout << "3.search train by no" << endl;
    cout << "4.Exit" << endl;
    cout << " Enter Your Choice No:";
    cin >> choiceno;

    if (choiceno == 1)
    {
        t.inputtraindeatails();
        t.display();
    }

    if (choiceno == 2)
    {
        trainrecords t[5];
        t[0].setdetail(1, "shanti express", "modasa", "indore", "08:10:00 pm");
        t[1].setdetail(2, "sabarmatiti express", "modasa", "Ahmedabad", "09:25:10 pm");
        t[2].setdetail(3, "bullet express", "modasa", "udaipur", "11:15:00 pm");
        t[3].setdetail(4, "kanpur express", "modasa", "kanpur", "12:30:00 pm");
        t[4].setdetail(5, "himachal express", "modasa", "manali", "07:45:00 am");
        for (int j = 0; j < 5; j++)
        {

            t[j].showtraindetails();
        }

        trainrecords::print();
    }
    if (choiceno == 3)
    {

        cout << "enter train no(GR ID):";
        cin >> searchno;
        flag = 0;
        trainrecords t[5] = {
            trainrecords(10961, "shanti express", "modasa", "indore", "08:10:00 pm"),
            trainrecords(10962, "sabarmatiti express", "modasa", "Ahmedabad", "09:25:10 pm"),
            trainrecords(10963, "bullet express", "modasa", "udaipur", "11:15:00 pm"),
            trainrecords(10964, "kanpur express", "modasa", "kanpur", "12:30:00 pm"),
            trainrecords(10965, "himachal express", "modasa", "manali", "07:45:00 am")};
        for (int i = 0; i < 5; i++)
        {
            if (t[i].getno() == searchno)
            {
                cout << "train found" << endl;
                t[i].showtraindetails();
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "no is wrong" << endl;
        }
    }
    if (choiceno == 4)
    {
        cout << "Existing The System.Good Bye !" << endl;
    }
    return 0;
}
