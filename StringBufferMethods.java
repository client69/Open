
public class StringBufferMethods {

	public static void main(String[] args)
	{
		StringBuffer sb=new StringBuffer("Java Coding");
		//1 length()
        System.out.println(sb.length());
        //2 capacity()
        System.out.println(sb.capacity());
        //3 charAt(int index)
        System.out.println(sb.charAt(8));
        //System.out.println(sb.charAt(90));
        
        //4 setCharAt(int index,char ch)
        sb.setCharAt(0, 'Y');
        System.out.println(sb);
        
       //5 append(String s) in string place we can use any primitive data type
        sb.append(true);
        sb.append(123);
        sb.append(123.123);
        sb.append('w');
        System.out.println(sb);
        
        //6 insert(int index ,String s) same as append()
        //but it is on specified location
        sb.insert(0,"Learn ");
        sb.insert(11,false);
        sb.insert(16, 1829.299);
        System.out.println(sb);
        
        //7 delete(int begin,int end) delete certain words
        sb.delete(16, 24);
        System.out.println(sb);
        
        //8 deleteCharAt(int index) delete specified index
        sb.deleteCharAt(11);
        System.out.println(sb);
        
        //9 reverse() reverse all characters
        sb.reverse();
        System.out.println(sb);
        sb.reverse();
        
        //11 setLength() only specified no of characters and remove
        ///all the remaining characters. 
        sb.setLength(10);
        System.out.println(sb);
        
        //12 trimToSize() To deallocate the extra allocated free memory 
        //such that capacity and size are equal. 
        StringBuffer sb1=new StringBuffer(1000);
        System.out.println(sb1.capacity());
        sb1.append("OM");
        System.out.println(sb1.capacity());
        sb1.trimToSize();
        System.out.println(sb1.capacity());
        
        //13 ensureCapacity(int initialcapacirty);
        //To increase the capacity dynamically(fly) based on our requirement
        StringBuffer sb2=new StringBuffer();
        System.out.println(sb.capacity());//16 
        sb2.ensureCapacity(1000);  
        System.out.println(sb2.capacity());//1000 
   
	}

}
