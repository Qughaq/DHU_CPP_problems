#include <iostream>
using namespace std;
using std::endl;

string remove(string string1, char char1){
    string temp;
    int i=0,j=0;
    int len=string1.length();
    for(i=0,j=0;i<len;i++)
    {
        if(string1[i]!=char1)
        {
            temp.append(1,string1[i]);
            j++;
        }
    }
    temp[j]='\0';
    return temp;
}

string remove(string string1, int index1){
    int len = string1.length();
    if (index1 >= len || index1 <0) {
        return string1;
    }else{
        for(int i=index1; i<len-1; i++)
        {
            string1[i]=string1[i+1];
        }
        string1 = string1.substr(0, len-1);
        return string1;
    }
}

string remove(string string1, int startIndex, int endIndex){
    int len = string1.length();
    if (startIndex >=0 && startIndex <=endIndex && endIndex < len){
        string temp1 = string1.substr(0, startIndex);
        string temp2 = string1.substr(endIndex + 1, len);
        return temp1 + temp2;
    }else {
        return string1;
    }
}

int main()
{
 int num, index, startIndex, endIndex;
 char delChar;
 string src, dest;

 while(cin >> num)
 {
  switch(num)
  {
   case 1:
    cin >> src >> delChar;
    cout << remove(src, delChar) << endl;
    break;
   case 2:
    cin >> src >> index;
    cout << remove(src, index) << endl;
    break;
   case 3:
    cin >> src >> startIndex >> endIndex;
    cout << remove(src, startIndex, endIndex) << endl;
    break;
  }
 }
 return 0;
}
