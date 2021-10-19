import java.util.Scanner;

public class egyptianFraction {
    
    public static void egyptianfraction(int nr,int dr){
        if(nr==0 || dr==0){
            return ;
        }

        if(dr%nr==0){
            System.out.print("1"+"/"+dr/nr);
            return ;
        }
        if(nr/dr==0){
            System.out.print(nr/dr);
        }

        if(nr>dr){
            System.out.print(nr/dr);
            egyptianfraction(nr%dr,dr);
            return;
        }

        int n = dr/nr + 1;
    
        System.out.print("1/"+n+" +");
        egyptianfraction(nr*n-dr, dr*n);
    }
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int nr=scn.nextInt();
        int dr=scn.nextInt();

        egyptianfraction(nr,dr);

        scn.close();
    }
}
