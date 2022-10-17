#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start,*newnode,*temp,*t,*q;
int main()
{
	int ch,c=0,ni1,ni2,ele1,ele2,e1,e2;
    void insertBeg();
    void insertEnd();
    int insertPos();
    void display();
    void deleteBeg();
    void deleteEnd();
    int deletePos();
    void nodeCount();
    void nthNode(int ni1);
    void nthlastEle(int ni2);
    void search(int ele1);
    void frequencyofEle(int ele2);
    void pallindrome();
    void swap(int e1,int e2);
     while(1)
    {
        printf("Enter 1.Insert 2.Delete 3.Display 4.Count 5.NthNodeData 6. NthLastEle 7.Search 8.Frequency 9.Pallindrome 10.Swap 11.Exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("1.Insert at beginning 2.Insert at end 3.Insert at specified position 4.Exit :");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1: insertBeg();
                                break;
                        case 2: insertEnd();
                                break;
                        case 3: insertPos();
                                break;
                        case 4: return(0);
                        default: printf("Wrong Choice\n");
                    }
                    break;
 
            case 2: printf("1.Delete from Beginning 2.Delete from End 3.Delete from Specified position 4.Exit :");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1: deleteBeg();
                                break;
                        case 2: deleteEnd();
                                break;
                        case 3: deletePos();
                                break;
                        case 4: return(0);
                        default: printf("Wrong Choice\n");
                    }
                    break;
            case 3: display();
                    break;
            case 4: nodeCount();
            		break;
            case 5: printf("Enter Node Index:");
            		scanf("%d",&ni1);
            		nthNode(ni1);
            		break;
            case 6: printf("Enter Node Index:");
            		scanf("%d",&ni2);
            		nthlastEle(ni2);
            		break;
            case 7: printf("Enter the Element to be Searched:");
            		scanf("%d",&ele1);
            		search(ele1);
            		break;
            case 8: printf("Enter the Element to Know Frequency:");
            		scanf("%d",&ele2);
            		frequencyofEle(ele2);
            case 9: pallindrome();
            		break;
            case 10:printf("Enter two Elements to Swap:");
            		scanf("%d %d",&e1,&e2);
            		swap(e1,e2);
            case 11: return(0);
            default: printf("Wrong Choice");
        }
    }
    return 0;
}
void insertBeg()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    if(start==NULL)       
    {
        t->next=NULL;
        start=t;
    }
    else
    {
        t->next=start;
        start=t;
    }
}
 
void insertEnd()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;
    if(start==NULL)
    {
        start=t;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=t;
    }
}
int insertPos()
{
    int pos,i,num;
    if(start==NULL)
    {
        printf("List is empty");
        return 0;
    }
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    t->data=num;
    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("UnderFlow");
            return 0;
        }
        q=q->next;
    }
    t->next=q->next;
    q->next=t;
    return 0;
}
void display()
{
    if(start==NULL)
    {
        printf("List is Empty");
    }
    else
    {
        q=start;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d ",q->data);
            q=q->next;
        }
    }
}
void deleteBeg()
{
    if(start==NULL)
    {
        printf("The list is Empty");
    }
    else
    {
        q=start;
        start=start->next;
        printf("Deleted element is: %d",q->data);
        free(q);
    }
}
 
void deleteEnd()
{
    if(start==NULL)
    {
        printf("The list is Empty");
    }
    else
    {
        q=start;
        while(q->next->next!=NULL)
        q=q->next;
        t=q->next;
        q->next=NULL;
        printf("Deleted element is: %d",t->data);
        free(t);
    }
}
 
int deletePos()
{
    int pos,i;
     if(start==NULL)
    {
        printf("List is Empty");
        return 0;
    }
    printf("Enter position to delete:");
    scanf("%d",&pos);
    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("UnderFlow");
            return 0;
        }
        q=q->next;
    }
    t=q->next;
    q->next=t->next;
    printf("Deleted element is: %d",t->data);
    free(t);
     return 0;
}

void nodeCount()
{
	int c=0;
	temp=start;
	while(temp->next!=NULL)
	{
		c++;
		temp=temp->next;
	}
	printf("%d",c);
}
void nthNode(int ni1)
{
	int i=0,c=0;
	temp=start;
	while(i<ni1-1)
	{
		temp=temp->next;
		i++;
	}
	printf("%d",temp->data);
}
void nthlastEle(int ni2)
{
	int i=0,c=0;
	temp=start;
	while(temp->next!=NULL)
	{
		c++;
		temp=temp->next;
	}
	
	
}
void search(int ele1)
{
	int flag=0;
	temp=start;
	while(temp->next!=NULL)
	{
		if(temp->data==ele1)
			flag=1;
		temp=temp->next;
	}
	if(flag==1)
		printf("Found");
	else
		printf("Not Found");
}
void frequencyofEle(ele2)
{
	int c=0;
	temp=start;
	while(temp->next!=NULL)
	{
		if(temp->data==ele2)
			c++;
		temp=temp->next;
	}
	printf("%d",c);
}
void pallindrome()
{
	int i=0,j=0,n=0,a[20],b[20];
	temp=start;
	while(temp->next!=NULL)
	{
		a[i]=temp->data;
		i++;
		n++;
		temp=temp->next;
	}
	for(i=n;i>0;i--)
		b[j++]=a[i];
	for(i=0;i<n;i++)
		if(a[i]==b[i])
			printf("Pallindrome");
		else
			printf("Not a Pallindrome");
}
void swap(int e1,int e2)
{
	int temp2=e2,temp3=e1;
	temp=start;
	while(temp->next!=NULL)
	{
		if(temp->data==e1)
		{
			temp->data=temp2;
		}
		if(temp->data==e2)
		{
			temp->data=temp3;
		}
		temp=temp->next;
	}
}

