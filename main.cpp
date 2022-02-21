#include <iostream>
#include <cmath>

using namespace std;

class Tpoint;
//--------------------------------------------------------------------------------
class Tcircle{
    int xO, yO;
    int r;
public:
    Tcircle(int get_x, int get_y, int get_r);
    void judge(Tpoint & p);
};
//--------------------------------------------------------------------------------
class Tpoint{
    int x, y;
    string name;
  public:
    Tpoint(int get_x, int get_y);
    friend void Tcircle::judge(Tpoint & p);
};
////Constructors//////////////////////////////////////////////////////////////////
Tpoint::Tpoint(int get_x, int get_y)
{
    x = get_x;
    y = get_y;
}
//---------------------------------------------------------------------------------
Tcircle::Tcircle(int get_x, int get_y, int get_r)
{
    xO = get_x;
    yO = get_y;
    r = get_r;
}
//*********************************************************************************
void Tcircle::judge(Tpoint & pt)
{
    int seg = sqrt(pow(pt.x-xO, 2) + pow(pt.y-yO, 2));

    if(seg < r ) cout << "I" ;
    else if(seg > r ) cout << "O" ;
    else if(seg == r ) cout << "E" ;
    cout << endl;
}
//**********************************************************************************
int main()
{
    int xO, yO, r, x , y, n;
    cin >> xO >> yO >> r;
    Tcircle Cir(xO, yO, r);
    cin >> n;
    while(n)
    {
        cin >> x >> y;
        Tpoint Poi(x, y);
        Cir.judge(Poi);
        n--;
    }

    return 0;
}
