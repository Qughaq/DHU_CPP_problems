#include <iostream>
#include <string>
using namespace std;

int main()
{
    string xml, bookname;
    getline(cin, xml);
    while (getline(cin, bookname))
    {
        string aim;
        int i, j;
        aim = "<name>" + bookname + "</name>";
        if (xml.find(aim) != -1)
        {
            i = xml.find(aim);
            i = xml.find("<price>", i);
            j = xml.find("</price>", i);
            cout << xml.substr(i + 7, j - i - 7) << endl;
        }
        else
        {
            cout << "No" << endl;
            continue;
        }
    }
    return 0;
}
