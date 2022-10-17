import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class DuplicateWords
{
	public void duplicateWord(String str)
	{
		Map<String, Integer> map=new HashMap<>();
		String[] words=str.split(" ");
		for(String s:words)
		{
			if(map.containsKey(s))
			{
				map.put(s,map.get(s)+1);
			}else
			{
				map.put(s,1);
			}
		}
		Set<String> ss=map.keySet();
		for(String s1:ss)
		{
			
				System.out.println(s1);
			
		}
	}
}
public class FindDuplicateWordsInString 
{

	public static void main(String[] args)
	{
		DuplicateWords dw=new DuplicateWords();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter any String Here...");
		String str=sc.nextLine();
		dw.duplicateWord(str);
	}

}
