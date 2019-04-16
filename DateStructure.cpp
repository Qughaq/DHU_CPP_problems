# include <iostream>
using namespace std;
using std::endl;

int ping[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int run[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

struct Date
{
    int year;
    int month;
    int day;
};

int GetAbsDays(Date x)
{
    int i;
    int month_day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int year = x.year-1;  // 因为欲求距离1年1月1日的距离
    int days = year * 365 + year/4 - year/100 + year/400;  //求得之前闰年的数量并在天数上进行想加
    if(x.year%4==0&& x.year%100!=0 || x.year%400==0)
        month_day[1]++; //当前年为闰年，二月加 1
    for(i=0; i<x.month-1; i++)
        days += month_day[i];
    days += x.day-1;  //今天应该是不算如天数计数
    return days;
}

int isLeap(int n)
{
    return ((n%4==0&&n%100!=0)||n%400==0)?1:0;
}


Date AddDay(Date d, int days){
    int i=0;
    for(i=0;i<days;i++)
    {
        if(isLeap(d.year)==0)
        {
            d.day++;
            if(d.day>ping[d.month])
            {
                d.day=1;
                d.month++;
                if(d.month>12)
                {
                    d.month=1;
                    d.year++;
                }
            }
        }
        else
        {
            d.day++;
            if(d.day>run[d.month])
            {
                d.day=1;
                d.month++;
                if(d.month>12)
                {
                    d.month=1;
                    d.year++;
                }
            }
        }
    }
    return d;
}
Date AddMonth(Date d, int months){
    d.month+=months;
    while(d.month>12)
    {
        d.month-=12;
        d.year++;
    }
    if(isLeap(d.year)==0)
    {
        if(d.day>ping[d.month])
        {
            d.day=ping[d.month];
        }
    }
    else
    {
        if(d.day>run[d.month])
        {
            d.day=run[d.month];
        }
    }
    return d;
}
Date AddYear(Date d, int years){
    d.year+=years;
    if(isLeap(d.year)==0 && d.month==2 && d.day>28)
            d.day=28;
    return d;
}
int Subtract(Date d1, Date d2){
    return GetAbsDays(d1) - GetAbsDays(d2);
}

int GetWeekDay(Date d1) {
    int iWeek = 0;
    int iYear = d1.year;
    int iMonth = d1.month;
    int iDay = d1.day;
    unsigned int y = 0, c = 0, m = 0, d = 0;
    if ( iMonth == 1 || iMonth == 2 )
    {
        c = ( iYear - 1 ) / 100;
        y = ( iYear - 1 ) % 100;
        m = iMonth + 12;
        d = iDay;
    }
    else
    {
        c = iYear / 100;
        y = iYear % 100;
        m = iMonth;
        d = iDay;
    }

    iWeek = y + y / 4 + c / 4 - 2 * c + 26 * ( m + 1 ) / 10 + d - 1;    //蔡勒公式
    iWeek = iWeek >= 0 ? ( iWeek % 7 ) : ( iWeek % 7 + 7 );    //iWeek为负时取模
    return iWeek;
}

int main()
{
    char WeekDayNames[][15]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday"};
    enum DayName {Sun, Mon, Tue, Wed, Thu, Fri, Sat}; // 定义枚举类型week
    int op;
    while(cin>>op)
    {
        Date d1, d2;
        int n;
        int w;
        switch(op)
        {
            case 1:  //add days
                cin>>d1.year>>d1.month>>d1.day>>n;
                d2=AddDay(d1, n);
                cout<<d2.year<<" "<<d2.month <<" " <<d2.day<<endl;
                break;
            case 2:
                cin>>d1.year>>d1.month>>d1.day>>n;
                d2=AddMonth(d1, n);
                cout<<d2.year<<" "<<d2.month <<" " <<d2.day<<endl;
                break;
            case 3:
                cin>>d1.year>>d1.month>>d1.day>>n;
                d2=AddYear(d1, n);
                cout<<d2.year<<" "<<d2.month <<" " <<d2.day<<endl;
                break;
            case 4:
                cin>>d1.year>>d1.month>>d1.day>>d2.year>>d2.month>>d2.day;
                n=Subtract(d1, d2);
                cout<<n<<endl;
                break;
            case 5:
                cin>>d1.year>>d1.month>>d1.day;
                w=GetWeekDay(d1);
                cout<<WeekDayNames[w]<<endl;
                break;
        }
    }
}
