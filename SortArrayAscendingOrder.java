import java.util.Scanner;

public class SortArrayInAscendingOrder
{
	public static void arrayAscending(int[]arr,int n)
	{
	int	temp=0;
	     	for(int i=0;i<n;i++)
	     	{
	     		for(int j=i+1;j<n;j++)
	     		{
	     			if(arr[i]>arr[j])
	     			{
	     			    	temp=arr[i];
	     			    	arr[i]=arr[j];
	     			    	arr[j]=temp;
	     			    	
	     			}
	     		}
	     	}
	     	System.out.println("Ascending Order:");
			for (int i = 0; i < n; i++) 
			{
				System.out.println(arr[i]);
			}
	}
	
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size of an array");
		int n=sc.nextInt();
		System.out.println("enter array elemnts");
		int[] arr=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}
		arrayAscending(arr,n);
	}

}
