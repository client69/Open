package ArrayRelatedPrograms;

public class ElementsAreInAscendingOrder {

	public static void main(String[] args) {
		int a[]= {5,2,6,7,8,1};
		ascendingOrder(a);
	}
	public static void ascendingOrder(int a[]) {
		int temp=0;
		for(int i=0;i<a.length;i++)
		{
			for(int j=i+1;j<a.length;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		System.out.println("Asceding order elements are...");
		for(int i=0;i<a.length;i++)
		{
			System.out.print(a[i]+" ");
		}
	}

}
