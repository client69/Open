import java.util.Scanner;

public class PrintCountOfPositiveNegetiveZero {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter any digit");
		int i, countp=0,countn=0,countz=0;
		int arr[]=new int[10];
		for(i=0;i<10;i++){
			arr[i]=scan.nextInt();
		}
		for(i=0;i<10;i++)
		{
			if(arr[i]<0)
			{
				countn++;
			}else if(arr[i]==0)
			{
				countz++;
			}else
			{
				countp++;
			}
		}
		System.out.println("It is negative number "+countn);
		System.out.println("It is a Zero Number "+countz);
		System.out.println("It is postive NUmber "+countp);
	}

}
