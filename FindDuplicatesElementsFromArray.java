import java.util.HashSet;
import java.util.Set;

public class FindDuplicatesElementsFromAnArray 
{

	public static void main(String[] args)
	{
		int duplicates[]= {1,51,1,5,1,41,51,12};
		Set<Integer> nonDuplicateSet=new HashSet<>();
		Set<Integer> DuplicateSet=new HashSet<>();
		for (Integer integer : duplicates) 
		{
		    if(!nonDuplicateSet.contains(integer))
		    {
		    	nonDuplicateSet.add(integer);
		    }else
		    {
		    	DuplicateSet.add(integer);
		    }
		}
		System.out.println("NONDuplicate Elements are"+nonDuplicateSet);
		System.out.println("Duplicate Elements are"+DuplicateSet);
		

	}

}
