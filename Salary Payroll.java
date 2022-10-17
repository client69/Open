import java.util.Scanner;
public class PayrollSal{

    public static void main(String args[]){

		double stax=0;
		Scanner in_num = new Scanner(System.in);
		System.out.println("Enter your salary:");
		double num1 = in_num.nextDouble();
		
 if(num1<=600){
	System.out.println("Tax is 0%: "+stax);
	System.out.println("NP: "+num1+" Birr");
		      }
 else if(num1<=1650){
	stax = num1*.10;	
	System.out.println("Tax is 10%: "+stax);
	System.out.println((num1-stax)+60+" Birr");
		      }
 else if(num1<=3200){
	stax = num1*.15;	
	System.out.println("Tax is 15%: "+stax);
	System.out.println((num1-stax)+142.50+" Birr");
		      }
 else if(num1<=5250){
	stax = num1*.20;	
	System.out.println("Tax is 20%: "+stax);
	System.out.println((num1-stax)+302.50+" Birr");
		      }
 else if(num1<=7800){
	stax = num1*.25;	
	System.out.println("Tax is 25%: "+stax);
	System.out.println((num1-stax)+565+" Birr");
		      }
 else if(num1<=10900){
	stax = num1*.30;	
	System.out.println("Tax is 30%: "+stax);
	System.out.println((num1-stax)+955+" Birr");
		      }
 else if(num1>10900){
	stax = num1*.35;	
	System.out.println("Tax is 35%: "+stax);
	System.out.println((num1-stax)+1500);
		      }
		
	in_num.close();
    }
}
