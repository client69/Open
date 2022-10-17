import java.util.Scanner;

public class ReverseAnumber {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter any Number...");
		int num=sc.nextInt();
		int rem,rev=0;
        while(num>0)
        {
        	rem=num%10;
        	rev=rev*10+rem;
        	num=num/10;
        }
        System.out.println("Reverse a number is "+rev);

	}

}
