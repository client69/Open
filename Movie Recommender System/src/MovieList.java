import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MovieList{

    protected ArrayList<ArrayList<String>> allMovielist = new ArrayList<ArrayList<String>>();
    protected ArrayList<String> handler =new ArrayList<String>();
    protected SignUp user;

    public MovieList(SignUp signUp)
    {
        genreAdd();
        user=signUp;
        if(user.movieSeen==null)
        {
            user.movieSeen= new HashMap<String,Integer>();
            intialValue();
        }
    }

    private void intialValue()
    {
         for(ArrayList<String> m:allMovielist){
             user.movieSeen.put(m.get(0),0);
         }
     }

    private void genreAdd()
    {
       addAction();
       addComedy();
       addRomance();
       addHorror();
       addSciFi();
       toPlay();
    }

    void searchDisplayGenres(){
        System.out.println("Please Enter Your Choice:");
        System.out.println("1. Action 2.Comedy 3.Romance 4.Horror 5.SciFi");
    }

    void searchDisplayMoviesThroughGenre(int x) throws Exception{
        System.out.println(allMovielist.size());
        if (x>=1 && x<=5) {
            for (int i=1; i<allMovielist.get(x-1).size(); i++) {
                System.out.println(allMovielist.get(x-1).get(i));
            }
            play((allMovielist.get(x-1).get(0)));
        }
        //System.out.println(allMovielist.get(0).get(0));
        //over here it throws eof exception
    }

    boolean toPlayFor4() throws IOException, InterruptedException {
        boolean res=true;
        System.out.println("Playable movies we have are :-");
        for(String i:allMovielist.get(5)){
            System.out.println(i);
        }
        System.out.println("Do you Want to Play it: 1.YES  2.NO ");
        BufferedReader br = new BufferedReader(new
                InputStreamReader(System.in));
        int c=Integer.parseInt(br.readLine());
        if(c==1){
            String movieName;
            boolean a=true;
            do{
                System.out.println("Enter movie you want to play :- ");
                movieName=br.readLine();
                for(String i:allMovielist.get(5)){
                    if(movieName.equals(i)){
                        a=false;
                        delay("Playing",5);
                        Thread.sleep(7000);
                        movieName=movieName.toLowerCase();
                        movieName=movieName.replaceAll("\\s","");
                        movieplay(movieName);
                        break;
                    }
                }
                if(a){
                    System.out.println("Please Enter the name Correctly");
                }
            }while (a);
        }
        else{
            res=false;
        }
        return res;
    }
    boolean play(String mvname) throws IOException, ClassNotFoundException, InterruptedException {
        boolean r=false;
        Scanner sc=new Scanner(System.in);
        System.out.println("Do you Want to Play it: 1.YES  2.NO ");
        int x=sc.nextInt();
        if(x==1) {
            mapUpdate(mvname);
            //new ProcessBuilder("cmd", "/c", "D:").inheritIO().start().waitFor();
           // new ProcessBuilder().command("C:\\Users\\rajpa\\mission.mp4");
           // movieplay(mvname.toLowerCase().trim());//pass mvname.toLowerCase().trim()
            r = false;
        }
        else{
            System.out.println("We are directing you to Main Menu");
            r=true;
        }return r;
    }
    boolean searchMovies(String s) throws IOException, ClassNotFoundException, InterruptedException {
        boolean x=true;
        boolean r=false;
        for(ArrayList<String> i:allMovielist)
        {
            for(String check:i)
            {
                if(check.equals(s))
                {
                    System.out.println("Movie Found SuccessFully");
                    x=false;
                    //code to add it to map
                    String a=getGenreType(s);
                    System.out.println("It is of "+a+" Genre");
                    if(play(a))
                        r=true;

                }
            }
        }
        if(x)
        {
            System.out.println("No Such Movie Found");
        }
        return r;
    }

    boolean searchMoviesExist(String s)
    {
        boolean x=false;
        for(ArrayList<String> i:allMovielist)
        {
            for(String check:i)
            {
                if(check.equals(s))
                {
                    x=true;
                    //code to add it to map
                    break;
                }
            }
        }
        return x;
    }

    public String getGenreType(String movie)
    {
        String s=null;
        for(ArrayList<String> x:allMovielist)
        {
            for(String i:x)
            {
                if(i.equals(movie))
                {
                    s= x.get(0);
                    break;
                }
            }
        }
        if(s==null) {
            return "No such movie found";
        }
        else return s;
    }

    public void mapUpdate(String genre) throws IOException, ClassNotFoundException {
        if(genre.equals("No such movie found")){
            return;
        }
        Map<String,Integer> userData=user.getMovieSeen();
        Map<String,Integer> update=new HashMap<String, Integer>();
        for (Map.Entry<String, Integer> entry : userData.entrySet()) {
           if(entry.getKey().equals(genre)){
               update.put(entry.getKey(),entry.getValue()+1);
           }
           else {
               update.put(entry.getKey(),entry.getValue());
           }
        }
        user.setMovieSeen(update);
        update=user.getMovieSeen();
        /*for(Map.Entry<String,Integer> x :update.entrySet()){
            System.out.println(x.getKey()+"  "+x.getValue());
        }*/
        WriteToFile writeToFile = new WriteToFile();
        writeToFile.fileWrite(writeToFile.readFile(),user,user.getEmail());
    }

    private void addAction()
    {
        handler.add("Action Movies");
        handler.add("Watchman");
        handler.add("Terminator: Dark Fate");
        handler.add("Star Wars: The Rise of Skywalker");
        handler.add("Zombieland: Double Tap");
        handler.add("El Camino: A Breaking Bad Movie");
        handler.add("Daybreak");
        handler.add("Equillibrium");
        handler.add("Running Scared");
        handler.add("Fast & Furious");
        handler.add("Unstoppable");
        handler.add("Shaft");
        handler.add("Die Hard");
        handler.add("Mission Impossible");
        handler.add("Revenge");
        handler.add("A touch of Zen");
        handler.add("Con Air");
        handler.add("Top Gun");
        handler.add("Expendables");
        handler.add("Rush Hour");
        handler.add("Air Force One");
        handler.add("Tekken");
        handler.add("Blade");
        handler.add("Bad Boys");
        handler.add("Batwoman");
        handler.add("mission");
        allMovielist.add(handler);
        handler=null;
    }

    private void addComedy()
    {
        handler =new ArrayList<String>();
        handler.add("Comedy Movies");
        handler.add("The Laundromat");
        handler.add("Living with Yourself ");
        handler.add("Zombieland: Double Tap");
        handler.add("Modern Love");
        handler.add("Hocus Pocus");
        handler.add("The Boys");
        handler.add("Dhammal");
        handler.add("Hera Pheri");
        handler.add("Phir Hera Pheri");
        handler.add("Munna Bhai M.B.B.S");
        handler.add("3 idiots");
        handler.add("Gol Maal");
        handler.add("Deadpool");
        handler.add("The Dictator");
        handler.add("Superbad");
        handler.add("Once Upon a Time in Hollywood");
        handler.add("Ted");
        handler.add("Zombieland");
        handler.add("Wedding Crashers");
        handler.add("Yes man");
        handler.add("Euro Trip");
        allMovielist.add(handler);
        handler=null;
    }

    private void toPlay(){
        handler =new ArrayList<String>();
        handler.add("Avengers Endgame");
        handler.add("Uri");
        handler.add("Mission Mangal");
        handler.add("Iron Man 3");
        handler.add("Captain America First Avenger");
        allMovielist.add(handler);
        handler=null;
    }

    private void addRomance()
    {
        handler =new ArrayList<String>();
        handler.add("Romantic Movies");
        handler.add("Game of Thrones");
        handler.add("Big Mouth");
        handler.add("Friends");
        handler.add("The King");
        handler.add("Maleficent");
        handler.add("Vikings");
        handler.add("Riverdale");
        handler.add("Crazy Rich Asians");
        handler.add("Me Before You");
        handler.add("Veer Zara");
        handler.add("Fanna");
        handler.add("Titanic");
        handler.add("The Vow");
        handler.add("Dilwale");
        handler.add("Before Midnight");
        handler.add("The Proposal");
        handler.add("Roy");
        handler.add("Dilwale Dulhaniya Le Jayenge");
        handler.add("27 Dresses");
        handler.add("The Holiday");
        allMovielist.add(handler);
        handler=null;
    }

    private void addHorror()
    {
        handler =new ArrayList<String>();
        handler.add("Horror Movies");
        handler.add("Zombieland: Double Tap");
        handler.add("The Walking Dead");
        handler.add("American Horror Story");
        handler.add("Supernatural");
        handler.add("It");
        handler.add("The Nun");
        handler.add("Conjuring");
        handler.add("Conjuring 2");
        handler.add("Annabella");
        handler.add("Halloween");
        handler.add("It Follows");
        handler.add("Ready Or Not");
        handler.add("Us");
        handler.add("Don't Breathe");
        handler.add("It Chapter Two");
        handler.add("Stranger Things");
        handler.add("3 from Hell");
        handler.add("Split");
        handler.add("Train to Busan");
        handler.add("Insidious");
        allMovielist.add(handler);
        handler=null;
    }

    private void addSciFi()
    {
        handler =new ArrayList<String>();
        handler.add("Sci-Fi Movies");
        handler.add("Watchmen");
        handler.add("Star Wars: The Rise of Skywalker");
        handler.add("Bloodshot");
        handler.add("Arrow");
        handler.add("The Flash");
        handler.add("Avengers: Endgame");
        handler.add("Black Mirror");
        handler.add("InterStellar");
        handler.add("Inception");
        handler.add("Arrival");
        handler.add("Martian");
        handler.add("Iron Man");
        handler.add("Spiderman");
        handler.add("Hulk");
        handler.add("Terminator");
        handler.add("Robot");
        handler.add("Transformer");
        handler.add("Edge of tomorrow");
        handler.add("Gravity");
        handler.add("Looper");
        handler.add("Sorce Code");
        handler.add("Snowden");
        handler.add("Wall-E");
        handler.add("Ad Stra");
        allMovielist.add(handler);
        handler=null;
    }

    void delay(String s,int x) throws IOException, InterruptedException {
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
        clearScreen();
    }

    void clearScreen() throws IOException,InterruptedException {
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    }

    void movieplay(String s){
        try
        {
            // Just one line and you are done !
            // We have given a command to start cmd
            // /K : Carries out command specified by string
            Runtime.getRuntime().exec(new String[] {"cmd", "/K", "F:\\movietoplay\\"+s+".mp4"});

        }
        catch (Exception e)
        {
            System.out.println("HEY Buddy ! U r Doing Something Wrong ");
            e.printStackTrace();
        }
    }
}
