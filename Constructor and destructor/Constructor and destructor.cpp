//Constructor and destructor
#include <iostream>
using namespace std;
class Base{
  private:
    int x; //Does nothing
  public:
    Base(){
    cout<<"Base constructor"<<endl;   //1st build after class creation
    }
    
    ~Base(){
        cout<<"Base destructor"<<endl; //last destruct after prg closes
    }
};
class derived:public Base
{
    private:
     int z; //Does nothing
    public:
     derived(){
    cout<<"derived constructor"<<endl; //2ed comes when derived obj is created
    }
    
    ~derived(){
        cout<<"derived destructor"<<endl; //3ed comes wen derived obj is closed
    }   
};
int main(){  //Function overriding  
    
    derived d_obj; //Creating and Calling derived class  obj
 return 0;   
}
