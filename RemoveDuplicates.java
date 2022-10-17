package ArrayRelatedPrograms;
import java.util.Arrays;
 
public class RemoveDuplicatesJavaExample 
{   

   public static void main(String[] args) 
    {       
        int arryWithDup[] ={4, 3, 2, 4, 9, 2};
        removeDuplicates(arryWithDup);      
    } 
   public static void removeDuplicates(int []arryWithDup)  
   {
	   System.out.println("Array with Duplicate Elements  ");
	   for(int i=0;i<arryWithDup.length;i++)
	   {
		   System.out.print(arryWithDup[i]+" ");
	   }
	   
	   System.out.println();
	   System.out.println("Array withOut Duplicate Elements  ");
	   int noOfUniqueElements=arryWithDup.length;
	   for(int i=0;i<noOfUniqueElements;i++)
	   {
		   for(int j=i+1;j<noOfUniqueElements;j++)
		   {
			   if(arryWithDup[i]==arryWithDup[j])
			   {
				   arryWithDup[j]=arryWithDup[noOfUniqueElements-1];
				   noOfUniqueElements--;
				   j--;
			   }
					   
		   }
	   }
	   int[] arryWithoutDup=Arrays.copyOf(arryWithDup, noOfUniqueElements);
			   for(int i=0;i<arryWithoutDup.length;i++)
			   {
				   System.out.print(arryWithoutDup[i]+" ");
			   }
   }	
}