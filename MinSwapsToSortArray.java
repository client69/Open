import java.util.Arrays;
import java.util.HashMap;

public class MinSwapsToSortArray {
    static int minSwaps(int[] arr) {
        HashMap<Integer, Integer> maps = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            maps.put(arr[i], i);
        }
        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = maps.get(arr[i]);
        }
        maps.clear();
        int swaps = 0;
        for (int i = 0; i < arr.length; i++) {
            int val = arr[i];
            if (val < 0)
                continue;
            while (val != i) {
                int newVal = arr[val];
                arr[val] = -1;
                val = newVal;
                swaps++;
            }
            arr[i] = -1;
        }
        return swaps;
    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of Elements in the Array");
        int size = Integer.parseInt(sc.next());
        int array = new int[n];
        for(int i=0;i<n;i++){
            array[i] = Integer.parseInt(sc.next());
        }
        int minSwaps = minSwaps(array);

        System.out.println("Minimum number of Swaps required to Sort the Array is : "+minSwaps);
    }
}
    
