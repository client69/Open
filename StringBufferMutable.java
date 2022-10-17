
public class DataTypesPractice {

	public static void main(String[] args) {
		byte b=123;
		short s=234;
		int i=234;
		int i1=0b1010;//bunary number to int
		System.out.println(i1);
		int u=0x1A;//hexdecimal number to int
		System.out.println(u);
		int p=01234;//octal number to int
		System.out.println(p);
		long l=83763;
		
		float f=10.1234f;
		double d=123.9732654734;
		System.out.println(d);
		double d1='e';//asscii to double
		System.out.println(d1);
		double d2=12_3__45.327_3;//we can use like this from 1.7 version
		System.out.println(d2);
		
		
		
		char c='r';
		char c1=97;//accii code to int
		System.out.println(c1);
      	char c2=0xFace;//hexdeceimal it prints ?
		System.out.println(c2);
		char c3='\u0050';//unicode characters
		System.out.println(c3);
				
		boolean bb=true;
		
		System.out.println(b+":"+s+":"+i+":"+l+":"+f+":"+d+c+bb);
	}

}
