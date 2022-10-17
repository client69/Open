import java.util.ArrayList;
import java.util.List;

public class FindDulicateNumbersInList {

	public static void main(String[] args) {
		
		List<Integer> list=new ArrayList<>();
		
		for(int i=0;i<10;i++)
		{
			list.add(i);
		}
      list.add(5);
      list.add(2);
   findDulicataes(list);
	}

	private static List<Integer> findDulicataes(List<Integer> list) {
		List<Integer> listWithoutDuplicates=new ArrayList<>();
		System.out.println("duplicate list is "+list);
		System.out.println("dulicate elements are  ");
		for(int i:list)
		{
			if(listWithoutDuplicates.contains(i))
			{
				System.out.print(i+" ");
			}else
			{
				listWithoutDuplicates.add(i);
			}
		}
		
		return listWithoutDuplicates;
	}

}
