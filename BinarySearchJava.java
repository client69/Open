//import java.io.*;
import java.util.*; 
class BinarySearchJava { 
    public static int binarySearch(int arr[], int l, int r, int x) 
    { 
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
            if (arr[mid] == x) 
                return mid; 
              if (arr[mid] > x) 
                return binarySearch(arr, l, mid - 1, x); 
            return binarySearch(arr, mid + 1, r, x); 
        } 
        return -1; 
    } 
    public static void main(String args[]) 
    { Scanner sc = new Scanner (System.in);
        System.out.println("enter number of elements");
        int n = sc.nextInt(); 
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("enter number to be searched");
        int x = sc.nextInt();
        int result = binarySearch(arr, 0, n - 1, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at " + (result+1)); 
            sc.close();
    } 
} 
