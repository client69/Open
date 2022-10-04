import java.util.ArrayList;
import java.util.Scanner;

public class minimumCoins {
    static int[] deno={1,2,3,10,20,50,100,500,1000};
    public static String getminimumCoins(int V){
        int n=deno.length;
        ArrayList<Integer> arr=new ArrayList<>();

        for(int i=n-1;i>=0;i--){
            while(V>=deno[i]){
                V-=deno[i];
                arr.add(deno[i]);
            }
        }

        StringBuilder sb=new StringBuilder();
        for(int val:arr){
            sb.append(val+" ");
        }

        return sb.toString();
    }
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        System.out.println(getminimumCoins(n));
        scn.close();
    }   
}
