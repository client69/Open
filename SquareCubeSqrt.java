import java.util.Scanner;

public class FindSqaureCubeSqrt 
{

	static public  void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter any Integer Number ");
        int num=sc.nextInt();
        System.out.println("Square of "+num+" is "+Math.pow(num, 2));
        System.out.println("cube of "+num+" is "+Math.pow(num, 3));
        System.out.println("Square Root of "+num+" is "+Math.sqrt(num));
	}

}
