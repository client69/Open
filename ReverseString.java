
import java.util.Arrays;
import java.util.Scanner;

public class ReverseString 
{

	public static void main(String[] args) 
	{
		Scanner in=new Scanner(System.in);
		System.out.println("Enter any String");
		String input=in.nextLine();
		char [] x=input.toCharArray();
		int size=input.length();
		char [] y=new char[size];
		int i=0;
		while(i!=size)
		{
			y[size-1-i]=x[i];
			i++;
		}
	
			System.out.println("Given string is "+new String(x));
			System.out.println("Reverse String "+new String(y));
		

	}

}
