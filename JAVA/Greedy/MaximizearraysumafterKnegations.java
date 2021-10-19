import java.util.Arrays;
import java.util.Scanner;

public class MaximizearraysumafterKnegations {

    static int maximumSum(int arr[], int n, int k)
    {
      
        for (int i = 1; i <= k; i++)
        {
            int min = +2147483647;
            int index = -1;
 
            for (int j = 0; j < n; j++)
            {
                if (arr[j] < min)
                {
                    min = arr[j];
                    index = j;
                }
            }
 
            if (min == 0)
                break;
 
            arr[index] = -arr[index];
        }
 
        // Calculate sum of array
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        return sum;
    }
    
    static int sol(int arr[], int k)
    {
        // Sorting given array using in-built
        // java sort function
        Arrays.sort(arr);
        int sum = 0;
 
        int i = 0;
        while (k > 0)
        {
            // If we find a 0 in our
            // sorted array, we stop
            if (arr[i] >= 0)
                k = 0;
 
            else
            {
                arr[i] = (-1) * arr[i];
                k = k - 1;
            }
 
            i++;
        }
 
        // Calculating sum
        for (int j = 0; j < arr.length; j++)
        {
            sum += arr[j];
        }
        return sum;
    }
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int k=scn.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=scn.nextInt();
        }
        System.out.println(maximumSum(arr,n,k));
        System.out.println(sol(arr,k));
        scn.close();
        
    }
}
