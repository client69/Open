
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Check {
    public static void main(String[] args) throws Exception {
      clearScreen();
      Scanner sc=new Scanner(System.in);
      boolean chk=true;
      do    {
          System.out.println("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                    System.out.println("SIGN UP press 1   |   LOGIN press 2   |    QUIT press 3:- ");
          System.out.println("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
          int x=sc.nextInt();
          try{
              if(x!=1 && x!=2 && x!=3)
                  throw new Exception("Please Enter a Valid Input!");
          }catch (Exception e){
              System.out.println(e.getMessage());
          }
          switch(x){
              case 1: {
                  SignUp sp=new SignUp();
                  sp.detailsToFile();
                  delay("Updating",5);
                  Thread.sleep(7000);
                  clearScreen();
                  break;
              }
              case 2:{
                  try {
                      Login lg = new Login();
                      clearScreen();
                  }catch (FileNotFoundException ex){
                      System.out.println("No One is Registered till now.\nSo,Please Create a account");
                  }
                  break;
              }
              case 3: {
                  delay("Quiting",3);
                  clearScreen();
                  Thread.sleep(5000);
                  chk=false;
              }
          }
      }while(chk);
}

    static void clearScreen() throws IOException, InterruptedException {
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    }

    static void delay(String s,int x){
        Thread thread=new Thread(new Runnable() {
            @Override
            public void run() {
                for(int i=0;i<x;i++){
                    {
                        try {
                            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        System.out.print(s);
                        for(int j=0;j<(i+1)*10;j++){
                            System.out.print(".");
                        }
                        try {
                            Thread.sleep(i*1000);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
        });
        thread.setPriority(5);
        thread.start();
    }
}
