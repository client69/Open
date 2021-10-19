import java.util.*;
// import java.lang.*;
// import java.io.*;

public class fractionalKnapSack {
    
    public static class item{
        int val;
        int wt,i;
        Double cost;
        public item(int a,int b,int c){
            val=a;
            wt=b;
            i=c;
            cost=(double)a/(double)b;
        }
    }

    public static class comp implements Comparator<item>{
	    @Override
	    public int compare(item a,item b){
	        return b.cost.compareTo(a.cost);
	    }
	}
	public static void getans(item[] arr,int n,int w){
	    Double ans=0.0;
	   for(int i=0;i<n;i++){
	       int wt=arr[i].wt;
	       int val=arr[i].val;
	       if(w-wt>0){
	           ans+=val;
	           w-=wt;
	       }
	       else{
	           double frac=(double)w /(double)wt;
	           ans+=frac*val;
	           w=(int)(w- (wt*frac));
	           break;
	       }
	       
	   } 
	   ans=ans*100;
	   ans=(double)Math.round(ans);
	   ans=ans/100;
	   System.out.println(ans);
	}
	public static void main (String[] args) {
		//code
		Scanner scn=new Scanner(System.in);
		int t=scn.nextInt();
		while(t>0){
		    int n=scn.nextInt();
		    int w=scn.nextInt();
		    item[] arr=new item[n];
		    for(int i=0;i<n;i++){
		        arr[i]=new item(scn.nextInt(),scn.nextInt(),i);
		    }
		    Arrays.sort(arr,new comp());
		    getans(arr,n,w);
		    t--;
		}
        scn.close();
	}
	
}
