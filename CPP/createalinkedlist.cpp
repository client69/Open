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
node *head=NULL, *tail=NULL, *temp=NULL;
void create(){
    int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=tail=temp=n;
        n->next=head;
    }
    else{
        temp->next=n;
        n->next=head;
        tail=n;
        temp=n;
    }
}
void display(){
    node *temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}
void insertend(){
     int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=tail=temp=n;
        n->next=head;
    }
    else{
        tail->next=n;
        n->next=head;
    }
}
void insertbegin(){
     int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=tail=temp=n;
        n->next=head;
    }
    else{
        n->next=head;
        tail->next=n;
        head=n;
    }
}
void insertatp(){
    int x,position;
    cin>>position>>x;
    node *n=new node(x);
    node *temp=head;
    int i=0;
    while(i+1<position-1){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
void deletebegin(){
    node *temp=head;
    head=head->next;
    tail->next=head;
    delete(temp);
}
void deleteend(){
    node *temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=head;
    tail=temp;
}
void reverse(){
    node *current=head;
    node *prev=NULL,*next=NULL;
    do{
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    while(current!=head);
    head->next=prev;
    head=prev;
}
int main(){
    create();
    create();
    create();
    insertbegin();
    insertend();
    insertatp();
    deletebegin();
    deletend();
    reverse();
    display();
}
