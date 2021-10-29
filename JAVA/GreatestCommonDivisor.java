import java.util.Scanner;
public class Main{

	public static int gcd(int a , int b){
		if(a % b == 0) return b;
		return gcd(b , a % b);	
	}

	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter Number 1: ");
		int x = input.nextInt();
		System.out.print("Enter Number 2: ");
		int y = input.nextInt();
		int gcd = gcd(x , y);
		System.out.printf("GCD of %2d and %2d is %2d",x,y,gcd);
	}
} 