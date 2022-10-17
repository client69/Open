import java.util.Arrays;
import java.util.Scanner;

public class FindMissingNumberInArray {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
	    System.out.println("Enter size of an array");
	    int size=sc.nextInt();
		int intArray[]= new int[size];
		System.out.println("Enter elements of array");
				for(int i=0;i<size-1;i++) {
					intArray[i]=sc.nextInt();
				}
		int missingNumber=getMissingNumber(intArray,size);
		System.out.println("Missing Number is"+Arrays.toString(intArray) +"is "+ missingNumber);

	}

	private static int getMissingNumber(int[] intArray, int n) {
		int expectedCal=(n*(n+1))/2;
		int actualCal=0;
		for(int i:intArray)
		{
			actualCal=actualCal+i;
		}
		return expectedCal-actualCal;
	}

}
