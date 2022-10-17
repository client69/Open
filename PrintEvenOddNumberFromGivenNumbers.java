package ArrayRelatedPrograms;

public class PrintEvenOddNumberFromGivenNumbers {

	public static void main(String[] args) {
		int a[]= {11,2,3,4,22,34,52,34,23,42,43,53,98,99};
		
		printEvenOddNumbers(a);
	}
	public static void printEvenOddNumbers(int[] a)
	{
		System.out.println("EVen numbers are ");
		for(int i=0;i<a.length;i++)
		{
			if(a[i]%2==0)
			{
				System.out.print(a[i]+" ");
			}
		}
		System.out.println();
		System.out.println("Odd numbers are ");
		for(int i=0;i<a.length;i++)
		{
			if(a[i]%2!=0)
			{
				System.out.print(a[i]+" ");
			}
		}
	}
}
