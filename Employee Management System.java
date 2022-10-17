//------ AI Programming ---------
// OOP Overview (Constructors)
// @freecodecs (c) October, 2019.

package employee;
import java.util.Scanner;

public class Employee {
	
	//variable declaration
    private String name;
    private int hrWork;
    private float rate;
    
    //Parameterized & non-parameterized constructors
	public Employee()
    {
        name = null;
        hrWork = 0;
        rate = 0;
    }
    public Employee(String n, int w, int r)
    {
        name = n;
        hrWork = w;
        rate = r;
    }
    
    //set object functions
	public void setName(String n)
    {
        name = n;
    }
    public void setHourWork(int w)
    {
        hrWork = w;
    }
    public void setRate(float r)
    {
        rate = r;
    }
    
    //get or display object functions
	public String getName()
    {
        return name;
    }
    public int getHourWork()
    {
        return hrWork;
    }
    public float getRate()
    {
        return rate;
    }
	
	//salary calculate method
    public void calSalary()
    {
        double salary;
        salary = hrWork * rate;
        
        System.out.println(name + "'s Salary is: " + salary);
    }
    
    
    public static void main(String[] args) {
        
		//Instantiate objects
		Employee Emp1 = new Employee();
        Employee Emp2 = new Employee("Abebe", 50, 100);
        
		 //call employee 2 object method
        Emp2.calSalary();
        
        Scanner userIn=new Scanner(System.in);
        
        // creating object by accepting data from user
		 System.out.println("Enter name: ");
        Emp1.setName(userIn.nextLine());
        
        System.out.println("Enter work hour: ");
        Emp1.setHourWork(userIn.nextInt());
        
        System.out.println("Enter Payment Rate: ");
        Emp1.setRate(userIn.nextFloat());
        
        //call employee 1 object method
		 Emp1.calSalary();
    }
    
}