/**
 * Implementation of Linear and Binary Searching
 */
package searching;

import java.util.Arrays;

/**
 * @author Bellatrix
 *
 */
public class Searching {

	//returns index for element found
	//returns -1 for not found
	static public int linearSearching(int[] arr, int n)
	{
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]==n)
				return i;
		}
		return -1;
	}
	
	
	//returns index for element found
	//returns -1 for not found
	static public int binarySearching(int[] arr, int n)
	{
		Arrays.sort(arr);
		int first = 0;
		int last = arr.length-1;
		boolean flag = false;
		while(first<=last)
		{
		int middle = first + (last-first)/2;
		if(arr[middle] == n)
		{
			return middle;
		}
		else if(n>arr[middle])
		{
			first = middle+1;
		}
		else
		{
			last = middle-1;
		}
		}
		
		return -1;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr = {1,2,3,8,9,0};
		System.out.println(binarySearching(arr, 9));

	}

}
