#include<iostream>
#include<string>
using namespace std;

int main()
{
    string string1,string2;
    int sum=0,i=0;
    while(cin>>string1>>string2)
    {
        sum=0;
        i=0;
        if(string1.find(string2,i)==-1)
        {
            cout<<sum<<endl;
            continue;
        }
        while(string1.find(string2,i)>=0)
        {
            sum++;
            i=string1.find(string2,i)+string2.length();
            if(i>string1.rfind(string2))
                break;
        }
        cout<<sum<<endl;
    }
    return 0;
}
