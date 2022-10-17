import java.util.Arrays;
import java.util.Scanner;

public class FindLargestNumberFormGivenArrray 
{

	public static void main(String[] args)
	{
		int array[]= {4,23,456,12,36};
		
		int LargeNum=0;
		int SecondLargeNum=0;
		for(int i=0;i<=array.length;i++)
		{
			if(LargeNum<array[i])
			{
				SecondLargeNum=LargeNum;
				LargeNum=array[i];
				
			}else {
			if(SecondLargeNum<array[i])
			{
				LargeNum=SecondLargeNum;
				SecondLargeNum=array[i];
			}
			System.out.println("Fisrt large Number"+LargeNum);
			System.out.println("Second Large Number"+SecondLargeNum);
			}
			
			
		}
		
	    
	    
  }
}