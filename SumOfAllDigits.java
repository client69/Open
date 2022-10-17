import java.util.Scanner;

public class SumOfAllDigits
{
    public static void main(String args[])
    {
        int i, n, sum=0, num;
        Scanner scan = new Scanner(System.in);
		
        System.out.print("How many Number You want to Enter to Add them ? ");
        n = scan.nextInt();
		
        System.out.print("Enter " +n+ " numbers : ");
        for(i=0; i<n; i++)
        {
            num = scan.nextInt();
            sum = sum + num;
        }
		
        System.out.print("Sum of all " +n+ " numbers is " +sum);
    }
}