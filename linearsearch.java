//importing packages
import java.util.*;
import java.lang.*;
import java.io.*;
class linearsearch
{
    public static int search(int arr[], int x)//Fuction which takes the array and the element to be searched for as arguments
    {
        int n = arr.length;
        for(int i = 0; i < n; i++)//going through all elements and returning 1 for the first occurence of the element
        {
            if(arr[i] == x)
                return i;
        }
        return -1;
    }
//driver function
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of elements you want to enter");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter Elements");
        for(int i=0;i<n;i++){
            //For Loop to read elements
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter element to be searched");
        int x = sc.nextInt();
        int result = search(arr, x);
        if(result == -1)
            System.out.print("Element is not present in array");
        else
            System.out.print("Element is present at index " + (1+result));//Using 1 based indexing
    }
}