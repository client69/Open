import java.util.Scanner;

public class RemoveDuplicateElementFromArray{
	public static void main(String[] args){
		/* Array instantiation */
		int[] arr_elements = new int[20];

		/* initial_element variable initialize by 0 and 
		point to the first element of the array */
		/* next_element points to next element of array */ 
		int j,k;
		int i;
		
		/*Create Scanner Object */
		Scanner sc = new Scanner(System.in);
		
		/*Display array size for user*/
		System.out.print("Enter array size: ");
		int arr_size = sc.nextInt();
		
		/*Display message for array element*/
		System.out.println("Read Array Elements From User :");

		/*Loop to take input array elements*/
		for(i=0;i<arr_size;++i)
		{
			System.out.print("Enter array elements of index " +i +": ");
			arr_elements[i] = sc.nextInt();
		}

		/* Display array before removing duplicate element */
		System.out.println("Before removing duplicate element array are :");

		/* Loop for displaying array elements */
		for(i=0;i<arr_size;++i)
		{
			System.out.println(arr_elements[i]);
		}

		/* Get new line
		System.out.println();
		/* Display array after removing duplicate array element */
		System.out.println("After removing duplicate element array are :");
		for(j=0;j<arr_size;++j)
		{
			for(k=j+1;k<arr_size;){
				/* if initial_element matches to next_element 
				then take next _element and matches till end */
				if(arr_elements[j] == arr_elements[k]){
					for(int temp = k; temp<arr_size; ++temp){
						arr_elements[temp] = arr_elements[temp+1];
					}
					arr_size = arr_size-1;		
				}		
				else
					k++;		
			}
		}
		
		/* Loop to display array after removing duplicate element */
		for(i=0;i<arr_size;++i)
			System.out.println(arr_elements[i]);
	}
}
