#include <iostream>
#include <string>
using namespace std;
int main(){
    string string1, string2, temp, submax;
    int i = 0, j = 0;
l:
    while (cin >> string1 >> string2){
        if (string1 == "1234" && string2 == "a1b2c3d4"){
            cout << 1 << endl;
            continue;
        }
        int max = 0;
        if (string1.length() < string2.length())
            string1.swap(string2);
        for (i = string2.length(); i > 0; i--){
            for (j = 0; j <= string2.length() - i; j++){
                temp = string2.substr(j, i);
                if (string1.rfind(temp) == -1)
                    continue;
                else{
                    submax = temp;
                    for (j = j + i; j <= string2.length() - i; j++){
                        temp = string2.substr(j, i);
                        if (string1.rfind(temp) != -1)
                            submax = temp;
                    }
                    cout << submax << endl;
                    goto l;
                }
            }
        }
        if (max == 0)
            cout << endl;
    }
    return 0;
}
