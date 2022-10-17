import java.util.StringTokenizer;
public class RemoveSpace{
public static void main(String [] args){
String str = "Instance of java";
StringTokenizer st = new StringTokenizer(str, " ");
StringBuffer sb = new StringBuffer();
while(st.hasMoreElements()){
sb.append(st.nextElement()).append(" ");
}
System.out.println(sb.toString().trim());
}
}