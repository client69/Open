import java.util.Scanner;

public class Ex21GasConsumption{

    public static void main(String args[]){
		Scanner userIn = new Scanner(System.in);
		
		System.out.println("Distance traveled in Kilometers: ");
		float dist = userIn.nextFloat();
		
		System.out.println("Total amount of gas used in liters: ");
		float gas = userIn.nextFloat();
		
		float kmConsp = dist / gas;
		float litConsp = gas / kmConsp;
		
		System.out.println("Distance \t Liters Used \t Km/Lt \t Lt/100Km");
		System.out.println(" " + dist + "  \t  " + gas + " \t " + kmConsp + "  \t  " + litConsp);
        
    }
}



