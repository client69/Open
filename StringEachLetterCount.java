import java.util.Scanner;

public class StringEachLetterCount 
{

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter any sentance");
		String s = sc.nextLine();
		System.out.println("Number of letter in given string  is "+l_Count(s));
		System.out.println("Number of letter in given string  is "+letterCount(s));

	}
	public static int letterCount(String str)
	{
		int l_count=0;
		for(int i=0;i<str.length();i++)
		{
			if(str.charAt(i)!=' ')
			{
				l_count++;
			}
		}
		return l_count;
	}
	//using recursion thod
	public static int l_Count(String str)
	{
		return str.length()-str.split(" ").length+1;
	}

}
