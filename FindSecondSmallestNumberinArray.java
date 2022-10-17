package ArrayRelatedPrograms;

public class FindSecondSmallestNumberInArray {

	public static void main(String[] args) {
		int a[]= {2,3,4,5,6,2,3,561,335,121,3241,1231,12,1,12};
		int size=a.length;
		System.out.println("Second Smallest NUmber is "+getSecondSmallestNumber(a,size));
	}
	public static int getSecondSmallestNumber(int a[],int size)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(a[i]<a[j])
				{
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		
		
		return a[size-2];
	}

}
