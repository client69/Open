import java.util.Scanner;

public class StringEachWordCount {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter any sentance");
		String s = sc.nextLine();
		System.out.println("Number of Words in given string  is "+WordCount(s));
		System.out.println("Number of Words in given string  is "+Word_Count(s));
		System.out.println("Number of Words in given string  is "+Word_CountE(s));
	}

	public static int WordCount(String s) {
		int w_count=1;
		for(int i=0;i<s.length();i++)
		{
			if(s.charAt(i)==' ')
			{
				w_count++;
			}
		}
		return w_count ;
	}
	//using Recursion
	public static int Word_Count(String s)
	{
		
		return s.split(" ").length;
	}

	//WHEN EXTRA SPACE IN STRING
	public static int Word_CountE(String s)
	{
		int W_Count=0;
		String str[]=s.split(" ");
		for(String word:str)
		{
			if(word.trim().length()>0)
			{
				W_Count++;
			}
		}
		return W_Count;
	}
}

