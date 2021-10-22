import java.util.Arrays;
import java.util.*;

public class maximumHeightOfPryamid {
    public static int sizeofpiramid(int[] arr , int n){
        Arrays.sort(arr);

        int prevlen=arr[0];
        int prevsize=1;
        int ans=1;
        int currlen=0;
        int currsize=0;
        for(int i=1;i<n;i++){
            currlen+=arr[i];
            currsize++;
            if(currlen>prevlen && currsize>prevsize){
                prevsize=currsize;
                prevlen=currlen;
                currlen=0;
                currsize=0;
                ans++;
            }
        }



        return ans;
    }
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=scn.nextInt();

        }
        System.out.println(sizeofpiramid(arr,n));
        scn.close();
    }
}
