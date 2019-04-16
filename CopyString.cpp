#include<iostream>
#include<string>
using namespace std;

string cpy(string string1)
{
    return string1;
}

string cpy(string string1,int startIndex)
{
    string temp;
    for(int i=startIndex;i<string1.length();i++)
    {
        temp+=string1[i];
    }
    return temp;
}

string cpy(string string1,int startIndex,int endIndex)
{
    int i=0;
    string temp;
    if(startIndex >=0 && startIndex <=endIndex && endIndex < string1.length()){

        for(i=startIndex;i<=endIndex;i++)
        {
            temp+=string1[i];
        }
        return temp;
    } else
    {
        return temp;
    }
}

int main()
{
    int num, startIndex, endIndex;
    string src, dest;

    while(cin >> num)
    {
        switch(num)
        {
            case 1:
                cin >> src;
                cout << cpy(src) << endl;
                break;
            case 2:
                cin >> src >> startIndex;
                cout << cpy(src, startIndex) << endl;
                break;
            case 3:
                cin >> src >> startIndex >> endIndex;
                cout << cpy(src, startIndex, endIndex) << endl;
                break;
        }
    }
    return 0;
}

