import java.util.Scanner;

class DesendingOrder
{
	public static void desendingOrder(int[] a,int n)
	{
	int temp=0;	
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
				{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				}
			}
		}
		System.out.println("Descending Order");
		for(int c:a)
		{
			System.out.println(c);
		}
	}
}
public class SortArrayDesendingOrder 
{

	public static void main(String[] args)
	{
		DesendingOrder d=new DesendingOrder();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size of an array");
		int size=sc.nextInt();
		System.out.println("Enter array elements....");
		int[] arr=new int[size];
		for(int i=0;i<size;i++)
		{
			arr[i]=sc.nextInt();
		}
		d.desendingOrder(arr,size);
	}

}
