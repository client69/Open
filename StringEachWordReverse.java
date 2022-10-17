import java.util.Scanner;

public class StringEachWordReverse
{

	public static void main(String[] args) 
	{
     Scanner sc=new Scanner(System.in);
     System.out.println("Enter any String");
     String s=sc.next();
     String word[]=s.split(" ");
     String reverse="";
     for(String sw : word)
     {
         StringBuilder sb = new StringBuilder(sw);
         sb.reverse();
         reverse=reverse+sb.toString();
      }
      System.out.println("The modified string is: " + reverse);
   
	}
}