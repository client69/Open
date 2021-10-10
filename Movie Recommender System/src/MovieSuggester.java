import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;

public class MovieSuggester extends MovieList {
    private ArrayList<String> moviesWatch;
    public MovieSuggester(SignUp signUp) {
        super(signUp);
    }

    private int indexOfGenre() {
        int y=0;
        for(ArrayList<String> x:allMovielist )
        {
            if(x.get(0).equals(maxGenre())){
                break;
            }
            y++;
        }
        return y;
    }

    private int movieSuggesttionSum() {
        int sum = 0;
        for (Map.Entry<String, Integer> entry : user.movieSeen.entrySet()) {
            sum += entry.getValue();
        }
        return sum;
    }

    private String maxGenre() {
        int max=0;
        String favGenre=null;
            for (Map.Entry<String, Integer> entry : user.movieSeen.entrySet()) {
                if (max <= entry.getValue()) {
                    max=entry.getValue();
                    favGenre = entry.getKey();
                }
            }
        return favGenre;
    }

    public void  getMovies()  {
        moviesWatch=new ArrayList<String>();
        if(movieSuggesttionSum()>=10) {
            for (int i = 0; i < 5; i++) {
                int z = (int) (Math.random() * (allMovielist.get(indexOfGenre()).size()-1)) + 1;//since first is genre name and movie start form 1st index not 0
                moviesWatch.add(allMovielist.get(indexOfGenre()).get(z));
            }
        }
        else {
            moviesWatch=getStartSuggestion();
        }
    }

    public ArrayList<String> getStartSuggestion()
    {
        ArrayList<String> y=new ArrayList<String>();
        for (int i = 0; i < 10; i++) {
            int z = (int)( Math.random() * allMovielist.size()) ;
            int q=(int)(Math.random()*(allMovielist.get(z).size()-1))+1;//since first is genre name and movie start form 1st index not 0
            y.add(allMovielist.get(z).get(q));
        }
        return y;
    }

    void getMenuDrive() throws Exception {
        Scanner sc=new Scanner(System.in);
        boolean chk=true;
        clearScreen();
        do{
            clearScreen();
            System.out.println("-------------------------------------------------------------------------------------------------------------------------------------");
            System.out.println("Welcome :- "+user.getUsername());
            System.out.println("-------------------------------------------------------------------------------------------------------------------------------------");
            System.out.println("BROWSE OUR MOVIES press 1   |   SEARCH OUR MOVIES press 2   |   OUR MOVIE RECOMMENDATIONS press 3   |   Playable Movies press 4:-  |   GO TO MAIN WINDOW press 5:- ");
            System.out.println("-------------------------------------------------------------------------------------------------------------------------------------");
            int x=sc.nextInt();
            try{
                if(x!=1 && x!=2 && x!=3 && x!=4 && x!=5)
                    throw new Exception("Please Enter a Valid Input!");
            }catch (Exception e){
                System.out.println(e.getMessage());
            }
            switch(x){
                case 1: {
                    clearScreen();
                    searchDisplayGenres();
                    int y=sc.nextInt();
                    try{
                        if(y!=1 && y!=2 && y!=3 && y!=4 && y!=5)
                            throw new Exception("Please Enter a Valid Input!");
                        delay("Loading",3);
                        Thread.sleep(5000);
                        clearScreen();
                        searchDisplayMoviesThroughGenre(y);
                        clearScreen();
                    }catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                    break;
                }
                case 2:{
                    clearScreen();
                    System.out.println("Enter movie you want to search");
                    BufferedReader br = new BufferedReader(new
                            InputStreamReader(System.in));
                    String movieName=br.readLine();
                    delay("Searching",3);
                    Thread.sleep(5000);
                    if(searchMovies(movieName))
                        continue;
                    Thread.sleep(3000);
                    clearScreen();
                    break;
                }
                case 3:{
                    clearScreen();
                    delay("Loading",3);
                    Thread.sleep(5000);
                    clearScreen();
                    System.out.println("Our Suggested Movies are :- ");
                    getMovies();
                    displaySuggestedMovies(moviesWatch);
                    askToPlay();
                    clearScreen();
                    break;
                }
                case 4:{
                    clearScreen();
                    if(toPlayFor4())
                        continue;
                    break;
                }
                case 5: {
                    clearScreen();
                    delay("We are transferring you to main window",2);
                    Thread.sleep(3000);
                    clearScreen();
                    chk=false;
                }
            }
        }while(chk);
    }

    private void displaySuggestedMovies(ArrayList<String> movieq)
    {
        for(String i:movieq)
        {
            System.out.println(i);
        }
    }

    private void playMovie(String movieName, ArrayList<String> suggested) throws IOException, ClassNotFoundException, InterruptedException {
        if(checkForSuggestedMovies(suggested,movieName)) {
            if (searchMoviesExist(movieName)) {
               // mapUpdate(getGenreType(movieName));
                play(getGenreType(movieName));
            } else {
                System.out.println("Please enter the correct name of movie as suggested");
            }
        }
        else {
            System.out.println("Please enter movie from suggested movie");
        }
    }

    private void askToPlay() throws IOException, ClassNotFoundException, InterruptedException {
        Scanner sc=new Scanner(System.in);
        boolean check=true;
        do {
            System.out.println("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            System.out.println("WATCH MOVIE press 1   |   EXIT PANEL press 2:-");
            System.out.println("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            int d=sc.nextInt();
            try{//Input mismatch Exception
                if(d!=1 && d!=2 )
                    throw new Exception("Please Enter a Valid Input!");
            }catch (Exception e){
                System.out.println(e.getMessage());
            }
          switch (d){
              case 1:{
                  System.out.print("Enter the movie you want to watch :- ");
                 // sc.skip("[\n]");
                  BufferedReader br = new BufferedReader(new
                          InputStreamReader(System.in));
                  String movieName = br.readLine();
                  playMovie(movieName, moviesWatch);
                  break;
              }
              default:{
                  System.out.println("Terminatting");
                  check=false;
                  break;
              }
          }
        }while (check);
    }

    private boolean checkForSuggestedMovies(ArrayList<String> q,String movieName){
        boolean a=false;
        for(String i:q){
            if(i.equals(movieName)){
                a=true;
                break;
            }
        }
        return a;
    }
}
