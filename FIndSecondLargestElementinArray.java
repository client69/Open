package ArrayRelatedPrograms;

public class FIndSecondLargestElementInArray {

	public static void main(String[] args) {
	   int[] a= {23,4,55,23,45,65,223,121,43,675};
	   int tot=a.length;
       System.out.println("Second largest number is "+getSecondLargest(a,tot));
	}
	public static int getSecondLargest(int[] a,int tot)
	{
		for(int i=0;i<tot;i++)
		{
			for(int j=i+1;j<tot;j++)
			{
				if(a[i]<a[j])
				{
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		return a[tot-2];
	}

}
