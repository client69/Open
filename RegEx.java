import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegExDemo {
   static int count=0;
	public static void main(String[] args) {
     Pattern p=Pattern.compile("ab");
     Matcher m=p.matcher("ababbab");
     while(m.find())
     {
    	 count++;
    	 System.out.println(m.start()+"...."+m.end()+"...."+m.group());
     }
     System.out.println("The number of oocurence are "+count);
	}
}
