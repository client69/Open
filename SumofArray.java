package ArrayRelatedPrograms;

public class SumOfArray {

	public static void main(String[] args) {
		int a[]= {24,3,5,46,56,78,12,3,44};
		sumOfElement(a);
	}
	public static void sumOfElement(int a[])
	{
		int sum=0;
		for(int i=0;i<a.length;i++)
		{
			if(a[i]>sum)
			{
				sum+=a[i];
			}
	
		}
		System.out.println("Sum Of element are  "+sum);
	}

}
