#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leet 876
ListNode* middleNode(ListNode* head) {
    if(head==nullptr || head->next==nullptr){ //this will get covered in while loop, still write this
                                              // everywhere  
                  return head;
    }    

    ListNode* slow=head;
    ListNode* fast=slow;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }        
    return slow;
}

//if we want to get mid to use in another question
ListNode *getMid(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//leet 206
ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    ListNode* prev=nullptr;
    ListNode* curr=head;
    ListNode* forw=nullptr;
    while(curr!=nullptr){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }        
    return prev;
}

ListNode* reverseData(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    ListNode* m=getMid(head);
    ListNode* c2=m->next;
    ListNode* c1=head;
    m->next=nullptr;

    ListNode* prev=nullptr;
    ListNode* curr=c2;
    while(curr!=nullptr){
        ListNode* forw=curr->next;

        curr->next=prev;
        prev=curr;
        curr=forw;
    }

    c2=prev;
    while(c1!=nullptr || c2!=nullptr){
        int t=c1->val;
        c1->val=c2->val;
        c2->val=t;

        c1=c1->next;
        c2=c2->next;
    }

    curr=prev;
    prev=nullptr;
    while(curr!=nullptr){
        ListNode* forw=curr->next;

        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    c2=prev;
    m->next=c2;
    return head;
}

//leet 234
 bool isPalindrome(ListNode* h) {
        if(h==nullptr || h->next==nullptr) return true;
        
        ListNode* s=h;
        ListNode* f=h;
        
        while(f->next!=nullptr && f->next->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }
        ListNode* b=s;
        ListNode* th=s->next;
        b->next=nullptr;
        
        ListNode* c2=reverseList(th);
         ListNode* c3=c2;
        ListNode* c1=h;
        //ListNode* c2=th;
        
        bool res=false;
        while(c1!=nullptr && c2!=nullptr){
            if(c1->val!=c2->val){
                res=false;
                break;
            } else res=true;
            c1=c1->next;
            c2=c2->next;
        }
        th=reverseList(c3);
        b->next=th;
        
        while(h!=nullptr){ cout<<h->val <<" "; h=h->next;}
        cout<<endl;
        
        return res;
}

//leet 143 =====================================================================================

void reorderList(ListNode* head) {
       if(head==nullptr || head->next==nullptr){
          return;
      }
        
        ListNode* s=head;
        ListNode* f=head;
    
        while(f->next!=nullptr && f->next->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }
        ListNode* b=s->next;
        s->next=nullptr;
        
        ListNode* th=b;
        th=reverseList(th);
        
        ListNode* c1=head;
        
        while(c1!=nullptr && th!=nullptr){
            ListNode* forw=c1->next;
            
            c1->next=th;
            ListNode* thf=th->next;
            
            th->next=forw;
            
            c1=forw;
            th=thf;
        }
    }

    //    ordering the List back to original =======================================================================
ListNode* th1=nullptr;
ListNode* tt1=nullptr;
ListNode* th2=nullptr;
ListNode* tt2=nullptr;

void addFirst(ListNode* node){
    if(th2==nullptr){
        th2=node;
        tt2=node;
    } else {
        node->next=th2;
        th2=node;
    }
}

void addLast(ListNode* node){
    if(th1==nullptr){
        th1=node;
        tt1=node;
    } else {
        tt1->next=node;
        tt1=node;
    }
}



ListNode* orderList(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    int c=1;
    ListNode* curr=head;
    while(curr!=nullptr){
        ListNode* forw=curr->next;
        curr->next=nullptr;
        if(c){
            addLast(curr);
        } else {
            addFirst(curr);
        }
        curr=forw;
    }
    tt1->next=th2;
    return th1;
}

//leet 21====================================================================================

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* c1=l1;
    ListNode* c2=l2;

    ListNode* node=new ListNode(-1);
    ListNode* h=node;

    while(c1!=NULL && c2!=nullptr){
        if(c1->val <c2->val){
            h->next=c1;
            c1=c1->next;
        }else {
            h->next=c2;
            c2=c2->next;
        }
        h=h->next;
    } 
    if(c1!=nullptr){
        h->next=c1;
    } else {
        h->next=c2;
    }       
    return node->next;
}

//Leetcode 148================================================
ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *mid = getMid(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    return mergeTwoLists(sortList(head), sortList(nhead));
}

// leet 23
ListNode* some(vector<ListNode*>& lists, int si, int ei){
    if(si==ei) return lists[si];

    int m=(si+ei)/2;

    return mergeTwoLists(some(lists,si,m),some(lists,m+1,ei));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n=lists.size();
    if(n==0) return nullptr;
    return some(lists,0,n-1);
}


// leet 23 using priority_queue ==========================================
 class compare {
    public: 
    bool operator()(const ListNode* a, ListNode* b) const
    {
        return a->val > b->val; // this-other
    }
};

ListNode* mergeKLists2(vector<ListNode*>& lists) {
    if(lists.size()==0) return nullptr;
    priority_queue<ListNode*,vector<ListNode*>,compare> pq;  

    for(ListNode* l: lists){
        if(l!=nullptr)
        pq.push(l);
    }   
    ListNode* dummy=new ListNode(-1);
    ListNode* curr=dummy;   
    while(pq.size()!=0){
        ListNode* rp=pq.top(); pq.pop();
        curr->next=rp;
        if(rp->next!=nullptr){
            pq.push(rp->next);
        }
        curr=curr->next;
    }
    return dummy->next;
}

//leet 25===========================================================================
int len(ListNode* h){
    ListNode* temp=h;
    int ans=0;
    while(temp!=nullptr){
        ans++;
        temp=temp->next;
    }
    return ans;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    int l=len(head);

    if(l<k) return head;

    ListNode* oh=nullptr;
    ListNode* ot=nullptr;

    ListNode* curr=head;

    int K=k;

    th2=nullptr;
    tt2=nullptr;
    while(curr!=nullptr && l>=k){
        while(K--){
            ListNode* next=curr->next;
            curr->next=nullptr;

            addFirst(curr);

            curr=next;
        }
        if(oh==nullptr){
            oh=th2;
            ot=tt2;
        } else {
            ot->next=th2;
            ot=tt2;
        }
        th2=nullptr;
        tt2=nullptr;
        l-=k;
        K=k;
    }
    ot->next=curr;
    return oh;
}

// leet 92 ==============================================================================

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }        
    ListNode* curr=head;
    int i=1;

    th2=nullptr;
    tt2=nullptr;

    ListNode* oh=nullptr;
    ListNode* ot=nullptr;

    while(curr!=nullptr){
        ListNode* next=curr->next;
        curr->next=nullptr;
        if(i>=m && i<=n){
            addFirst(curr);
        } else if(i<m) {
            if(oh==nullptr){
                oh=curr;
                ot=curr;
            } else {
                ot->next=curr;
                ot=curr;
            }
        } else if(i==n+1){
            if(oh==nullptr){
                oh=th2;
                ot=tt2;
            } else {
                ot->next=th2;
                ot=tt2;
            }
            ot->next=curr;
            ot=curr;
            th2=nullptr;
            tt2=nullptr;
        } else {
            ot->next=curr;
            ot=curr;
        }
        i++;
        curr=next;
    }
    //linking when n==size of ll;
    if(oh==nullptr){
        oh=th2;
        ot=tt2;
    } else if(th2!=nullptr){
        ot->next=th2;
        ot=tt2;
    }

    return oh;
}

// leet 141 =========================================================================

 bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        return slow==fast;
}

ListNode *detectCycle(ListNode *head) {
     if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
    if(slow!=fast) return nullptr;

    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }

    return slow;
}

// Insight
ListNode *detectCycle2(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    int m = 0, x = 0, y = 0, z = 0;
    int disOfSlow = 0;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        disOfSlow++;
        if (slow == fast)
            break;
    }

    if (slow != fast)
        return nullptr;

    slow = head;
    ListNode *node = fast;
    while (slow != fast)
    {
        if (fast == node)
            m++;
        x++;
        slow = slow->next;
        fast = fast->next;
    }

    y = disOfSlow - x;

    return slow;
}

// leet 160 ============================================================================
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;
        ListNode* temp=headA;
        ListNode* curr=headA;
        while(temp!=nullptr){
            curr=temp;
            temp=temp->next;
        }
        curr->next=headB;
        ListNode* res=detectCycle(headA);
        curr->next=nullptr;
        return res; 
}

// leet 19 ==================================================================================
 ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr  || n==0){
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
       while(n--){
           fast=fast->next;  // n aage pahuch gya fast
       }
        if(fast==nullptr){ 
            return head->next; // if n==1 
        }
        while(fast->next!=nullptr){
            slow=slow->next; // slow is now at n-1 from last
            fast=fast->next;
        }
        ListNode* temp=slow->next;  
        slow->next=slow->next->next;
        temp->next=nullptr;
        return head;
}

//leet 61 ==========================================================================
ListNode* rotateRight(ListNode* h, int k) {
        if(h==nullptr || h->next==nullptr || k==0) return h;

        int l=len(h);

        //for k>n
        k=(k%l);
        if(k==0) return h;
        
        ListNode* s=h;
        ListNode* f=h;

        // k aage chale gaye
        while(k--){
            f=f->next;
        }

        // jisko naya h banana use ek pahle aa gaye
        while(f->next){
            s=s->next;
            f=f->next;
        }
        
        f->next=h; // cycle bana fi;
        h=s->next; // heaf naya vala 
        s->next=nullptr; // link tod diya 
        return h;
}

// === // https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list/0
// still not done

ListNode *segregateOddEven(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *even = new ListNode(-1);
    ListNode *ep = even;

    ListNode *odd = new ListNode(-1);
    ListNode *op = odd;

    ListNode *curr = head;
    while (curr != nullptr)
    {
        if (curr->val % 2 == 0)
        {
            ep->next = curr;
            ep = ep->next;
        }
        else
        {
            op->next = curr;
            op = op->next;
        }

        curr = curr->next;
    }

    ep->next = odd->next;
    return even->next;
}

ListNode* cons(){
    ListNode* head=new ListNode(1);
    ListNode* temp=head;
    int i=10;
    int j=2;
    while(i--){
        temp->next=new ListNode(j);
        j++;
        temp=temp->next;
    }
    return head;
}

void solve(){
   ListNode* head=cons();
   ListNode* ans=middleNode(head);
   cout<<ans->val;
}

int main(){
    solve();
}