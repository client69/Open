#include <iostream>

using namespace std;

int whoWins(int h, int x, int y, bool p)
{
    if(h < 0)
        return 0;
    if(h == 1 || h == x || h == y)
        if(p)
            return 1;
        else
            return 0;
    return whoWins(h - 1, x, y, ~p) || whoWins(h - x, x, y, ~p) || whoWins(h - y, x, y, ~p);
}

int main(int argc, char const *argv[])
{
    int h,x,y;
    cin>>h>>x>>y;
    if(whoWins(h, x, y, true) == 1)
        cout<<"Beerus"<<endl;
    else
        cout<<"Whis"<<endl;
    return 0;
}
