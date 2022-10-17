import java.util.Scanner;

public class SwapTwoNumbersWithOutAddSub {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter First Number ");
        int a=sc.nextInt();
        System.out.println("Enter Second Number ");
        int b=sc.nextInt();
        System.out.print("Before Swapping is ");
        System.out.println(a+ " " +b);
        a=a^b;
        b=a^b;
        a=a^b;
        System.out.print("After Swapping is ");
        System.out.println(a+ " " +b);

	}

}
