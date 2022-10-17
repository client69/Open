import java.util.Scanner;

public class PrintDiamondShapOfStars 
{

	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Number of Rows ");
        int n=sc.nextInt();
        //For Upper Shape is
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1-i;j++)
			{
				System.out.print(" ");
			}
			for(int k=0;k<i+1;k++)
			{
				System.out.print("* ");
			}
			System.out.println();
		}
		//For NUpper Shape is
		for(int m=0;m<n-1;m++)
		{
			for(int k=0;k<m+1;k++)
			{
				System.out.print(" ");
			}
			for(int r=0;r<n-1-m;r++)
			{
				System.out.print("* ");
			}
			System.out.println();
		}

	}

}
