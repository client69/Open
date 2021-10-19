import java.util.Scanner;

public class getSmallestDigit {

    public static String smallestno(int sum,int m){
        if (sum == 0)
        {
            return "Smallest number is 0 Not possible";
        }

        if (sum > 9*m)
        {
            return "Not possible";
        }
      
        sum--;
        int[] arr=new int[m];
        for(int i=m-1;i>0;i--){
            if(sum>9){
                arr[i]=9;
                sum-=9;

            }else{
                arr[i]=sum;
                sum=0;
            }
        }
        arr[0]=sum+1;
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<m;i++){
            sb.append(arr[i]);
        }

        return sb.toString();
    }
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int sum=scn.nextInt();
        int m=scn.nextInt();
        System.out.println(smallestno(sum,m));
        scn.close();
    }
}
