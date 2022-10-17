
public class FindLargestAndSmallestNumberInArray {
   public static void maxValue(int[] ar)
   {
	    int maxValue=ar[0];
	   for(int i=0;i<ar.length;i++)
	   {
		   if(ar[i]>maxValue)
		   {
			   maxValue=ar[i];
		   }
	   }
	   
	   System.out.println("Maximum of value is "+maxValue);
   }
   public static void minValue(int[] ar)
   {
	   int minValue=ar[0];
	   for(int i=0;i<ar.length;i++)
	   {
		   if(ar[i]<minValue)
		   {
			  minValue=ar[i];
		   }
	   }
	   System.out.println("Minimum of  value is "+minValue);
   }
	public static void main(String[] args) {
		int[] arr= {2,5,1,1,52,12,5};
	maxValue(arr);
		minValue(arr);
	}

}

