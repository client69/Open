import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class FindMaximumOccuringCharacter
{

	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter any String");
		String x=s.nextLine();
		char y[]=x.toCharArray();
		int size=y.length;
		Map<Character,Integer> map=new HashMap<>();
		int i=0;
		while(i!=size)
		{
			if(map.containsKey(y[i])==false)
			{
				map.put(y[i],1);
			}else
			{
				int oldval=map.get(y[i]);
				int newval=oldval+1;
				map.put(y[i],newval);
			}
          i++;
		}
		int maxkey=' ';
		int maxval=0;
		Set<Map.Entry<Character,Integer>> heap=map.entrySet();
		for(Map.Entry<Character,Integer> data:heap)
		{
			if(data.getValue()>maxval)
			{
				maxval=data.getValue();
				maxkey=data.getKey();
				
			}
			
		}
 			System.out.println(maxval);
			System.out.println(maxkey);
				
	}

}
