#include <iostream>
using namespace std;
using std::endl;

string padLeft(string string1, unsigned int n, char padding = ' ')
{
    string temp;
    if (n <= string1.length())
        return string1;
    temp.append(n - string1.size(), padding);
    temp.append(string1);
    string1 = temp;
    return string1;
}

string padRight(string string1, unsigned int n, char padding = ' ')
{
    if (n <= string1.length())
        return string1;
    string1.append(n - string1.size(), padding);
    return string1;
}
int main()
{
    int num, length;
    char padding;
    string src;

    while (cin >> num)
    {
        switch (num)
        {
        case 11:
            cin >> src >> length;
            cout << padLeft(src, length) << endl;
            break;
        case 12:
            cin >> src >> length >> padding;
            cout << padLeft(src, length, padding) << endl;
            break;
        case 21:
            cin >> src >> length;
            cout << padRight(src, length) << endl;
            break;
        case 22:
            cin >> src >> length >> padding;
            cout << padRight(src, length, padding) << endl;
            break;
        }
    }
    return 0;
}
