import java.util.Scanner;

public class PrintPatternAlphabet
{

	public static void main(String[] args)
	{
		int alphabet=65;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Number of Rows");
        int row=sc.nextInt();
        System.out.println("Here your Pattern");
        for(int i=0;i<row;i++)
        {
        	for(int j=0;j<i;j++)
        	{
        		System.out.print((char)alphabet);
        		alphabet++;
        	}
        	System.out.println();
        }
	}

}
