import java.util.Scanner;

public class PrintMultiplicationTable {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Which table You Want...");
		int num=sc.nextInt();
		System.out.println("-----------------------------");
		System.out.println("Multiplication table is ");
		for(int i=1;i<=10;i++)
		{
			System.out.println(num+" * "+i+" = "+num*i);
		}
		System.out.println("--------N---------------------");

	}

}
