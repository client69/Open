import java.util.Scanner;

public class SumOfEvenAndOddNUmbersInString {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter size of an array");
		int len = sc.nextInt();
		int arry[] = new int[len];
		System.out.println("Enter array elements ");
		for (int i = 0; i < len; i++) {
			arry[i] = sc.nextInt();
		}
		System.out.println("Sum of All numbers are " + SumOfAllNumber(arry, len));
		System.out.println("Sum of even numbers are " + SumOfEvenNumber(arry, len));
		System.out.println("Sum of odd numbers are " + SumOfOddNumber(arry, len));
	}

	// sum of all numbers in an array
	private static int SumOfAllNumber(int[] arry, int len) {
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum = sum + arry[i];
		}

		return sum;
	}

	// sum of Odd numbers in an array
	private static int SumOfOddNumber(int[] arry, int len) {
		int s_num = 0;
		for (int i = 0; i < len; i++) {
			if (arry[i] % 2 == 1V) {
				s_num += arry[i];
			}
		}
		return s_num;

	}

	// sum of Even numbers in an array
	private static int SumOfEvenNumber(int[] arry, int len) {
		int s_num = 0;
		for (int i = 0; i < len; i++) {
			if (arry[i] % 2 == 0) {
				s_num += arry[i];
			}
		}
		return s_num;
	}

}
