#include <iostream>
#include <string>
using namespace std;

class student{
private:
    string name;
    int math, english, sum;

public:
    student(string sName, int sMath, int sEnglish){
        name = sName;
        math =sMath;
        english = sEnglish;
    }
    student(){
        ;
    }
    string getName(){
        return name;
    }
    int getMath(){
        return math;
    }
    int getEnglish(){
        return english;
    }
    int getTotal(){
        return sum;
    }
    void calcTotal(){
        sum = math + english;
    }
    int put(){
        return sum;
    }
};

void sortStudent(student *s, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (s[j].put() < s[j + 1].put())
                swap(s[j], s[j + 1]);
}

int main(){
    student s[3],temp;
    string sName;
    int sMath, sEnglish;

    for(int i=0; i<3; i++){
        cin>>sName>>sMath>>sEnglish;
        s[i]=student(sName, sMath, sEnglish);
        s[i].calcTotal();
    }

    sortStudent(s, 3);

    for(int i=0;i<3;i++)
        cout<<s[i].getName()<<" "<<s[i].getMath()<<" "<<s[i].getEnglish()<<" "<<s[i].getTotal()<<endl;
    return 0;
}
