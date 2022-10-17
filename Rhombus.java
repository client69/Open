import java.util.Scanner;

public class StarPatternRambus {

	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a Number ....");
		int n=sc.nextInt();
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
		for(int x=0;x<n-1;x++)
		{
			for(int y=0;y<x+1;y++)
			{
				System.out.print(" ");
			}
			for(int z=0;z<-1-x;z++)
			{
				System.out.print("* ");
			}
			System.out.println();
		}
			
	}

}
