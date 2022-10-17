import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;

public class ReverseElementUsingHashSet
{
   public static void main(String[] args)
   {
	   
	 List set=new ArrayList();
	 set.add("om");
	 set.add("omdk");
	 set.add("oddm");
	 set.add("ojonsm");
	 
	 Collections.reverse(set);
	 System.out.println(set);
}
}
