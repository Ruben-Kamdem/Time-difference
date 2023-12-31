#include <iostream>
using namespace std;

class Time 
{
    public:
        int hour;
        int minutes;
    // Declaration des constructeur
        Time (){
            hour=0;
            minutes=0;
        }   
        Time(int hr, int min){
            hour=hr;
            minutes=min;
        }
};

void display (int hr_diff, int min_diff, int n){
    if(n==1){
        cout<<"Time 1 is "<<hr_diff<<"hrs "<<min_diff<<" mins ahead of Time 2"<<endl;
    }
    else if (n==-1)
        cout<<"Time 1 is "<<hr_diff<<"hrs "<<min_diff<<"mins behind Time 2"<<endl;
    else
        cout<<"Time 1 is same as Time 2"<<endl;
}

void time_difference (Time t1, Time t2){
    // Verify if they have the same hour
    int hr_diff=0, min_diff=0;
    if (t1.hour == t2.hour){
        hr_diff=0;
        min_diff=t1.minutes - t2.minutes;
        if (min_diff>0)
            display(hr_diff,min_diff,1);  //1 for ahead
        else if (min_diff<0) 
            display(hr_diff,-min_diff,-1);  //-1 for behind
        else
            display(hr_diff,min_diff,0);  // 0 for same
    }

    else if(t1.hour>t2.hour){
        hr_diff=t1.hour - t2.hour;
        min_diff=t1.minutes+60-t2.minutes; // to obtain the mins difference betwen the teo times
        if (min_diff<60){  // if min_diff<60 then it means there's (in reality) not up to an hr diff between the too.
            hr_diff--;
            display(hr_diff, min_diff,1);
        }
        else { // This is the case where mins diff is >60, and therefore, there's effectively more than an hr diff betn the two
            min_diff-=60;
            display(hr_diff,min_diff,1);
        }
    }

    else if (t1.hour<t2.hour){
        hr_diff=t2.hour-t1.hour;
        min_diff=t2.minutes+60-t1.minutes;
        if (min_diff<60){
            hr_diff--;
            display(hr_diff,min_diff,-1);
        }
        else{
            min_diff-=60;
            display(hr_diff,min_diff,-1);
        }
    }
}

int main()
{
    int h,m;
    cout<<"WELCOME TO THE TIME DIFFERENCE CALCULATOR"<<endl<<endl;
    cout<<"Please enter various times :"<<endl;
    cout<<"*******Time 1*******"<<endl;
    cout<<"\tHour : ";   cin>>h;
    cout<<"\tMinute : ";  cin>>m;
    Time time1(h,m);
    cout<<"*******Time 2*******"<<endl;
    cout<<"\tHour : ";   cin>>h;
    cout<<"\tMinute : ";  cin>>m;
    Time time2(h,m);
    time_difference(time1,time2); 

    cout<<"This is the end of the program. \nThank You for using our time difference calculator"<<endl;

    return 0;
}