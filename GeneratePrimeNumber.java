import java.util.Scanner;

public class GeneratePrimeNumbers {

	public static void main(String[] args) {
	int start,end,i,j,count=0;
	Scanner scan=new Scanner(System.in);
	System.out.println("Enter a range");
	System.out.println("Enter starting Number");
	start=scan.nextInt();
	System.out.println("Enter ending Number");
	end=scan.nextInt();
	for(i=start;i<end;i++)
	{
		count=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				count++;
				break;
			}
		}
		if(count==0)
		{
			System.out.print(i+" ");
		}
	}
	}

}
