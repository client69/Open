class Palindrome
{
    // Function to check if linked list is palindrome
    boolean isPalindrome(Node head) 
    {
        //Your code here
        Node slow=head;
        boolean flag=true;
        Stack<Integer> stack = new Stack<Integer>(); 
        while(slow!=null){
            stack.push(slow.data); 
            slow = slow.next;
        }
        while(head!=null){
            int i = stack.pop(); 
            if (head.data == i) { 
                flag = true; 
            } 
            else { 
                flag = false; 
                break; 
            } 
            head = head.next; 
        } 
        return flag; 
        }
        
    } 
//this program will tell you how to create the linked list 
//single linked list program
/*in the below program it has seprate function for 
creating,displaying , insertingat begning , insert at any particlar point , insertion at the end , deletion from end, deletion from begining reversong the list */

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node *head=NULL,*temp;
void display(){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void create(){
    int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=temp=n;
    }
    else{
        temp->next=n;
        temp=n;
    }
}
void insertbegin(){
    int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=n;
    }
    else{
        n->next=head;
        head=n;
    }
}  
void insertatend(){
    int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=n;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}
void insertatp(){
    int pos,x;
    cin>>pos>>x;
    node *n=new node(x);
    int i=0;
    node *temp=head;
    while(i+1<pos-1){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
void deletebegin(){
    if(head==NULL)
    return;
    else{
    node *temp=head;
    head=temp->next;
    delete(temp);
    }
}
void deleteend(){
    if(head==NULL)
    return;
    else{
        node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
}
void reverse(){
    node *current=head;
    node *prev=NULL;
    node *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
int main(){
    create();
    create();
    insertbegin();
    insertatend();
    insertatp();
    deletebegin();
    deleteend();
    reverse();
    display();
}
