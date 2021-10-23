package Java.Sort;

import java.util.*;
class BubbleSort{
    public static void bubbleSort(int[] a){

        int len = a.length;
        for(int i = 0; i < len - 1; i++){
            for(int j = 0; j < len - i -1; j++){
                if(a[j] < a[j+1]){
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }

        bubbleSort(a);

        for(int i = 0; i < n; i++){
            System.out.println(a[i]);
        }

        sc.close();
    }
}