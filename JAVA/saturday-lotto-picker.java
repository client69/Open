//OzLotto Number Picker
//Author: Marcus Visic
public class LotterynumbersArray {

public static void main(String[] args) {

// TODO Auto-generated method stub

boolean[] drawnball;

int[] lotterynumbers;

int randomnumber =0;

lotterynumbers= new int[9];

drawnball= new boolean[45];

for ( int i =0; i < lotterynumbers.length; i ++){

if (i==0){

randomnumber=(int) (Math.random()*44+1);

lotterynumbers[0]=randomnumber;

drawnball[randomnumber-1]=true;

}

randomnumber=(int) (Math.random()*44+1);

while (drawnball[randomnumber-1]==true){

randomnumber=(int) (Math.random()*44+1);

}

drawnball[randomnumber-1]=true;

lotterynumbers[i] = randomnumber;

}

for ( int i =0; i <= 8; i ++){

System.out.println("Saturday Lotto Number " + (i+1) + " is: " + lotterynumbers[i]);

}

}

}
