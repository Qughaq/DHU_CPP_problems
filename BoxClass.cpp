#include <iostream>
using namespace std;

class Box{
private:
    int Length;  //Box的长度
    int Width;   //Box的宽度
    int Height;  //Box的高度
    int volume;  //Box的体积
    int area;    //Box的表面积

public:
    //设置Box的尺寸
    void initBox( int x, int y, int z){
        Length = x;
        Width = y;
        Height = z;
    }

    //计算Box的体积
    void setVolume( ){
        volume = Length * Width * Height;
    }

    //计算Box的表面积
    void setArea( ){
        area = 2 * (Length * Width + Length * Height + Width * Height);
    }

    //输出盒子的信息，输出形式见“输出说明”
    void show( ){
        cout << Length << " " << Width << " " << Height << endl;
        cout << volume << endl;
        cout << area << endl;
    }
};

int main(){
    int intLength, intWidth, intHeight;
    Box box;
    cin>>intLength;
    cin>>intWidth;
    cin>>intHeight;
    box.initBox(intLength,intWidth,intHeight);
    box.setVolume();
    box.setArea();
    box.show();
    return 0;
}
