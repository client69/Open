import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class SetEntryExample
{

	public static void main(String[] args) 
	{
		String[] s= {"Apple","Banana","Guvav","Apple","Orange"};
		List<String> list=Arrays.asList(s);
		Map<String,Integer> map=new HashMap<>();
		for(String so:list)
		{
			if(map.containsKey(so))
			{
				map.put(so, map.get(so)+1);
			}else
			{
				map.put(so, 1);
			}
		}
		 Set<Entry<String, Integer>> entry= map.entrySet();
		 for(Entry<String, Integer> pp:entry)
		 {
			 System.out.println(pp.getKey()+" : "+pp.getValue()	);
		 }
		
	}

}
