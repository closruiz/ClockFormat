//Carlos Ruiz
//SNHU 22EW1
//CS-210-T1111

#include<iostream>

using namespace std;

// Time class 
class Time
{
    public:
    int h1,h2,m1,m2,s1,s2;

    // default constructor
    // Two clocks, on in 12 hour format and another in a 24 hour format
    
    Time()
    {
        this->h1 = 11;
        this->h2 = 23;
        this->m1 = 59;
        this->m2 = 59;
        this->s1 = 59;
        this->s2 = 59;
    }
    
    // time limit for each action 
    // checking both seconds and minutes to not exceed 60
    void managetime(int t=1)
    {
        if(t==1)
        {
            if(s1/60>0)
            {
                s1 %= 60;
                m1++;
            }
            if(m1/60 > 0)
            {
                m1 %= 60;
                h1++;
            }
            if(h1/12>0)
            {
                h1 %= 12;
                if(h1==0)
                    h1=12;
            }
        }
        if(t==2)
        {
            if(s2/60>0)
            {
                s2 %= 60;
                m2++;
            }
            if(m2/60 > 0)
            {
                m2 %= 60;
                h2++;
            }
            if(h2/24>0)
            {
                h2 %= 23;
                if(h2=24)
                    h2=00;
            }
        }

    }
    // the function to add 1 sec
    void addSecond()
    {
        s1++;
        s2++;
        managetime(1);
        managetime(2);
    }

    // the function to wait 1 sec
    void waitSecond()
    {
        s1++;
        s2++;
        managetime(1);
        managetime(2);
    }

    // the function to add 1 min
    void addMinute()
    {
        m1++;
        m2++;
        managetime(1);
        managetime(2);
    }

    // the function to add 1 hour
    void addHour()
    {
        h1++;
        h2++;
        managetime(1);
        managetime(2);
    }

    // the function for displaying  both times
    void display()
    {
        printf("\n12-hour Clock: %02d:%02d:%02d\n",h1,m1,s1);
        printf("24-hour Clock: %02d:%02d:%02d\n\n",h2,m2,s2);
    }
};

int main()
{
    Time t ;
    int p,n,m,f=1;
    
    
    // Menu as given in flowchart
    while(f>0)
    {
        t.display();
        cout<<"Change time on clocks? (1:YES, 2:NO): "<<endl;
        cin>>p;
        if(p==1)
        {
            cout<<"Choose option\n1. Add Time\n2. EXIT\nEnter 1 or 2: ";
            cin>>n;

            if(n==1)
            {
                cout<<"Choose an option\n1. Add 1 hour\n2. Add 1 minute\n3. Add 1 second\nEnter 1 or 2 or 3: ";
                cin>>m;

                switch(m)
                {
                    case 1: t.addHour(); break;
                    case 2: t.addMinute(); break;
                    case 3: t.addSecond();
                }
            }
            if(n==2)
            {
                f=-1;
            }
        }
        else if(p==2)
        {
            t.addSecond();
            t.waitSecond();
        }
    }
}
    