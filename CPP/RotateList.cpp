#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL) {
            return head;
        }
        int size=0;
        
        ListNode *temp=head;
        while(temp->next!=NULL) {
            size++;
            temp=temp->next;
            
        }
        size++;
        temp->next=head;
        ListNode *cur=head;
        k=k%size;
        for(int i=0;i<size-k-1;i++) {
            cur=cur->next;
        }
        ListNode* res=cur;
        res=res->next;
        cur->next=NULL;
        return res;
    }
};

int main() {
ListNode *root=new ListNode(5);
root->next=new ListNode(7);
root->next->next=new ListNode(8);
Solution obj;
ListNode result=obj.rotateList(root,2);
return 0;
}