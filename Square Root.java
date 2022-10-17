import java.util.Scanner;

public class Ex15SquareRoot{

    public static void main(String args[]){
		Scanner userIn = new Scanner(System.in);
		
		System.out.println("Input number : ");
		float num = userIn.nextFloat();
		
		double result = Math.sqrt(num);
		
		System.out.println("The square root of " + num + " is : " + result);
    }
}



