#include <iostream>
using namespace std;
int main()
{
    int X;
    int Y;
    int A;
    while (Y!=X)
{
    A=0;
    X=5;
    cout <<"guess a number from 1-10: ";
    cin >>Y;
    if (Y!=X)
    {
       A=A+1;
    }
    if (Y!=X && A!=3)
{
        cout <<"answer is wrong try again"<<endl;
}
else if (A==3 && Y!=X)
{
 cout <<"game over"<<endl;
}
}
}

}
