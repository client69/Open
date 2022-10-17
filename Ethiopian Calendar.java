//-------- AI Programming ----------
//   Ethiopian Age Calculator
// Join our Underground Coding Movement
//@freecodecs (c) Oct, 2019.


//package runstudent;
import java.util.Scanner;

class Date{
    int date;
    int month;
    int year;
}

class Student {
    String name;
    Date dob;

    public Student(String n, Date db)
    {
        name = n;
        dob = db;
    }

    public void calAge()
    {
        int calcDate, calcMonth, calcYear;
        int pag=28; //pagume
        
        Date curD=new Date();
        Scanner usIn = new Scanner(System.in);
        
        System.out.print("Enter Current : \nDate - ");
        curD.date = usIn.nextInt();
        System.out.print("Month - ");
        curD.month = usIn.nextInt();
        System.out.print("Year - ");
        curD.year = usIn.nextInt();
        
        if (curD.year%4 == 3) { pag= 6; }
        else { pag = 5; }
        
        int []months = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5};
        months[12] = pag;
        
        if(dob.date > curD.date){
            curD.month = curD.month -1;
            curD.date = curD.date + months[curD.month];
        }
        if(dob.month > curD.month){
            curD.year = curD.year - 1;
            curD.month = curD.month +13;
        }
        
        if(dob.year < curD.year){
            String y="year, ", m="month, ", d="day.";
        
            calcDate = curD.date - dob.date;
            calcMonth = curD.month - dob.month;
            calcYear = curD.year - dob.year;

            if(calcDate > 1) {d="days.";}
            if(calcMonth >1) {m="months, ";}
            if(calcYear >1) {y="years, ";}

            System.out.println("------------");
            System.out.println(name+"'s Age is: "+ calcYear + y + calcMonth + m + calcDate + d);    
        } 
        else if(dob.year > curD.year){
            System.out.println("------------");
            System.out.println("Current Date is incorrect! or \n"+name+" will born in the feature ?"); 
        }
    }
  
        
}

public class Main_G{
   
    public static void main(String[] args) {
        Date DOB = new Date();
        Scanner userIn = new Scanner(System.in);
        
        System.out.println("-- Ethiopian Calendar Age Calculator --");
        System.out.print("Enter Name: ");
        String userN = userIn.nextLine();
        
        System.out.print("Enter Date of Birth: \nDate - ");
        DOB.date = userIn.nextInt();
        System.out.print("Month - ");
        DOB.month = userIn.nextInt();
        System.out.print("Year - ");
        DOB.year = userIn.nextInt();
        
        Student Std = new Student(userN, DOB);
        System.out.println("------------------------------");
        Std.calAge();
        System.out.println("------------------------------");
    }

}
