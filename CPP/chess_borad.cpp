#include<iostream>
using namespace std;
int main()
{
    cout<<"-----------------"<<endl;
  char line[8][17]={"rkbkqbkr","pppppppp","        ","        ","        ","        ","pppppppp","rkbkqbkr"};
  for (int i=0;i!=8;i++)
  {
        for (int j=0;j!=8;j++)
        {
            cout <<"|"<<line[i][j];
        }
        cout<<"|"<<endl;
        cout <<"-----------------"<<endl;
  }
}
