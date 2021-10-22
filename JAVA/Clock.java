package JAVA;
//An algorithm which takes in time in 24 hour format and displays it in 12hour format(AM/PM)
//for example: 15hr 125mins 69secs will be calculated and displayed as  5:6:9 PM

import java.util.*;

class Clock {
    int hours , minutes, seconds;
    //parametrised constructor
    Clock(int h,int m,int s){
        hours=h;
        minutes= m;
        seconds=s;
    }
    void time(){
        //method to display time in 12hour format
        String amPm = "AM", time;

        if (hours >= 12){
            if (hours>12){
                hours -= 12;
            }
            amPm = "PM";
        }
        time="Time: "+hours+":"+minutes+":"+seconds+" "+amPm;
        System.out.println(time);
    }
   public static void main(String args[]){
    int hours, minutes, seconds;
     //Scanner class object
     Scanner sc = new Scanner(System.in);
    
     //user input
     System.out.println("Enter the hour for the time : ");
     hours = sc.nextInt();
     System.out.println("Enter the minutes for the time : ");
     minutes = sc.nextInt();
     System.out.println("Enter the seconds for the time : ");
     seconds = sc.nextInt();
        sc.close();
     //validation of the time input
     if (hours>=0 && hours <=24 && minutes >=0 && seconds >=0){
           
            if (minutes>=60){
                hours += (int)minutes/60;
                minutes -= 60*((int)minutes/60);
            }
            if (seconds >=60){
                minutes += (int)seconds/60;
                seconds -= 60*((int)seconds/60);
            }
            if (hours>=24){
                hours -= 24;
            }
            Clock ob = new Clock(hours,minutes,seconds);
            ob.time();
     }
     else{
         System.out.println("Wrong Input.Try Again! Enter correct time format.");
         main(args);
     }
   }
}
