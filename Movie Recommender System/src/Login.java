import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class Login {
    private String uemail,upassword;
    private WriteToFile writeToFile=new WriteToFile();

    Login() throws Exception {
        Scanner sc=new Scanner(System.in);
        if(checkForUserSignedIn()){
            clearScreen();
            System.out.println("Some User is Already Signed in");
            System.out.println("Continue with current account Press 1 :- \nFor Sign Out press 2:- \nElse we are closing the application");
            int c=sc.nextInt();
            if(c==1){
                if(getUsers()==null){
                    System.out.println("Any user has not been logged in");
                }
                else {
                    delay("Logging In",3);
                    Thread.sleep(4000);
                    MovieSuggester movieSuggester=new MovieSuggester(getUsers());
                    movieSuggester.getMenuDrive();
                    return;
                }
            }
            if(c==2)
            {
                delay("Signing Out",2);
                Thread.sleep(4000);
                clearScreen();
                signOut();
            }
            else {
                System.out.println("Terminatting");
                System.exit(0);
            }
        }
        else {
            getDetailsFromUser();
            searchEmailId();
        }
    }

    void searchEmailId() throws Exception {
        ArrayList<SignUp> signUps = writeToFile.readFile();
        boolean checke = true, checkp = true;
        int index=0;
           do {
               for (SignUp i : signUps) {
                   if (i.getEmail().equals(getUemail())) {
                       do {
                           checke=false;
                           if (i.getPasswd().equals(getUpassword())) {
                               checkp = false;
                               delay("Authenticating",5);
                               Thread.sleep(7000);
                               clearScreen();
                               System.out.println("Logged in Successfully");
                               i.setLoginStatus(true);
                               writeToFile.fileWrite(writeToFile.readFile(),i,index);//this will make changes to file
                               MovieSuggester movieSuggester=new MovieSuggester(i);
                               movieSuggester.getMenuDrive();
                               break;
                           }
                           else {
                               System.out.println("Please enter your password correctly");
                               Scanner s = new Scanner(System.in);
                               upassword = PasswordField.readPassword("Enter your password :-");
                           }
                       } while (checkp);
                   }
                   index++;// checks for the users index
               }
               if(checke)
               {
                   System.out.println("Please enter your email id correctly");
                   Scanner s = new Scanner(System.in);
                   uemail = s.nextLine();
                   index=0;
               }
           } while(checke);
    }

    public boolean checkForUserSignedIn() throws IOException, ClassNotFoundException {
        boolean a=false;
        ArrayList<SignUp> users=writeToFile.readFile();
        for(SignUp i:users)
        {
            if(i.isLoginStatus()) {
                a = true;
                break;
            }
        }
        return a;
    }

    private void getDetailsFromUser()
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter your registered email id :- ");
        setUemail(sc.nextLine());
        setUpassword(PasswordField.readPassword("Enter your password :-"));
    }

    public String getUemail() {
        return uemail;
    }

    public void setUemail(String uemail) {
        this.uemail = uemail;
    }

    public String getUpassword() {
        return upassword;
    }

    public void setUpassword(String upassword) {
        this.upassword = upassword;
    }

    public void signOut() throws IOException, ClassNotFoundException {
        boolean a=false;
        ArrayList<SignUp> users=writeToFile.readFile();
        for(int i=0;i<users.size();i++)
        {
            if(users.get(i).isLoginStatus())
            {
                users.get(i).setLoginStatus(false);
                writeToFile.fileWrite(writeToFile.readFile(),users.get(i),i);
            }
        }
    }

    SignUp getUsers() throws IOException, ClassNotFoundException {
        SignUp user=null;
        boolean a=false;
        ArrayList<SignUp> users=writeToFile.readFile();
        for(int i=0;i<users.size();i++)
        {
            if(users.get(i).isLoginStatus())
            {
               user =users.get(i);
               break;
            }
        }
        return user;
    }

    private void clearScreen() throws IOException,InterruptedException {
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    }

    void delay(String s,int x){
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
