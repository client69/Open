
public class ReverseAnArray 
{

	public static void main(String[] args) 
	{
		int a[]= {1,2,6,2,5,12,5,12,1,5,12};
		System.out.println("Original array");
		for(int i=0;i<a.length;i++)
		{
			System.out.println(a[i]);
		}
		System.out.println("Reverse array");
		for(int i=a.length-1;i>0;i--)
		{
			System.out.println(a[i]);
		}
		}

}
