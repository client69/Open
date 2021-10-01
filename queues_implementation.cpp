#include<iostream>

using namespace std;
#define ignore() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long
#define n 100


//array implementation
class queue{

    int* arr;
    int front;
    int back;

    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;

    }

    void push(int x ){
        if(back==n-1){
            cout<<"Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1)
        {
            front++;
        }
    }

    void pop(){
        if(front==-1  || front>back){
            cout<<"Underflow"<<endl;
            return;
        }

        front++;
    }

    int peek(){
         if(front==-1  || front>back){
            cout<<"Underflow"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
         if(front==-1  || front>back){
            
            return true;
        }
        return false;
    }
    
};

int main()
{
    
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.peek()<<endl;
    q.pop();

     cout<<q.peek()<<endl;
    q.pop();

     cout<<q.peek()<<endl;
    q.pop();

     cout<<q.peek()<<endl;
    q.pop();


    
    

    return 0;
}