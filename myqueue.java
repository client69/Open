import java.util.*;
class myqueue
{ int q[];
  int max=100;
  int front,rear;

  public myqueue()
  { 
    max=5;
    q=new int[max];
    front=rear=-1;
  }
  public myqueue(int m)
  { max=m;
    q=new int[max];
    front=rear=-1;
  }

  void insert(int num)
  { 
    // System.out.println(max+" max, rear "+rear);
    if(rear==max-1)
    {
      System.out.println("Queue is full");
    }
    else if(rear==-1)
    {
      front++;
      rear++;
      q[rear]=num;
    }    
    else
    {
      rear++;
      q[rear]=num;
    }
  } // End of insert
  
  int delete()
  {int temp=-999;
   if(front==-1)
   {System.out.println("Queue empty");
    return temp;}
   else if(front==rear)
        {temp=q[front];
         front=-1;rear=-1;
         return temp;}
        else
        {temp=q[front];
         front++;
         return temp;}  
  }

  void traverse()
  {
    if(front>-1)
    {
      for(int i=front;i<=rear;i++)
      {
      System.out.print(q[i]+" ");
      }  
     System.out.println();
    }
  }  
  
  public static void main(String[] args) 
  {
   myqueue m1= new myqueue(5);
   Scanner sc= new Scanner(System.in);
   int ch=1;
    while(ch != 4) //menu driven program
      {
        System.out.println("Enter choice:\n1.insert\n2.delete\n3.traverse\n4.exit");
        ch=sc.nextInt();
        switch(ch)
        {
          case 1:System.out.println("Enter num to insert");
                 int num=sc.nextInt();
                 int x=num;
                 m1.insert(x);
                 break;
        case 2: System.out.println(m1.delete());
                break;
        case 3: m1.traverse();
                break;
        //case 4:System.exit([]);
        default: m1.traverse();
                 break;
        }
      }
  }
  
}
