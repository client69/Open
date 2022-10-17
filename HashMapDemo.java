import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class HashMapDemo {

	public static void main(String[] args) {
		
		Map<String, Integer> map=new HashMap();
		map.put("Om Prakash", 1000);
		map.put("Manjula", 1200);
		map.put("Satyam",800);
		map.put("Preethi",1100);
		System.out.println(map);
		System.out.println(map.put("Om Prakash",500));
		System.out.println(map);
		
		System.out.println("-----------Only Keys------------");
		Set s= map.keySet();
		System.out.println(s);
		Iterator itr1=s.iterator();
		while(itr1.hasNext())
		{
			System.out.println(itr1.next());
		}
		
		System.out.println("----------Only Values-------------");
		Collection c=map.values();
		System.out.println(c);
		Iterator itr2=c.iterator();
		while(itr2.hasNext())
		{
			System.out.println(itr2.next());
		}
		
		System.out.println("----------Keys and Values-------------");
		Set s1=map.entrySet();
		System.out.println(s1);
		Iterator itr=s1.iterator();
		while(itr.hasNext())
		{
			Map.Entry m1=(Map.Entry)itr.next();
			System.out.println(m1.getKey()+"-----"+m1.getValue());
			if(m1.getKey().equals("Preethi"))
			{
				m1.setValue(8888);
			}
			System.out.println(m1.getKey()+"-----"+m1.getValue());
		}
	}

}

