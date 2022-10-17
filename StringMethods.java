
public class StringMethods {

	public static void main(String[] args) {
		//1
		String s="Learn java";
		System.out.println(s.charAt(3));
		
		//2
		String s1="Learn";
		String s2=s1.concat("Java");
		System.out.println(s2);
		       String s3=s1+"Java";
		       System.out.println(s3);
		              s1+="Java";
		              System.out.println(s1);
		              
		              //3&4
		              String a="java";
		              System.out.println(a.equals("JAva"));
		              System.out.println(a.equalsIgnoreCase("JAva"));
		              
		              //5
		              String b1="";
		              System.out.println(b1.isEmpty());
	
		              //6
		              String c1="Java;";
		              System.out.println(c1.length());
		              
		 //7
		 String d1="abababa";
		 System.out.println(d1.replace('a','b'));
		 
		 //8  substring method one argument which starts with begin until end
		 String e1="Learn Java";
		 System.out.println(e1.substring(6));
		 
		//9 two arugment in substring method which starts with begin end with end-1
		 String f1="Learn Java Coding";
		 System.out.println(f1.substring(6, 10));
		 
		 //10
		 String g1="ababba";
		 System.out.println(g1.indexOf('a'));
		 //11
		 System.out.println(g1.lastIndexOf('a'));
		 
		 //12&13
		 String h1="OMPRAKSH";
		 String h2="omprakash";
		 System.out.println(h1.toLowerCase());
		 System.out.println(h2.toUpperCase());	 
		 
	}

}
