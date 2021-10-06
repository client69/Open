import java.util.Scanner;

/**
  * Prompts user to enter two dimensional array and returns the location of the largest element 
*/
public class Ex8_13 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in); //scanner class for inputs
    
    System.out.println("Enter the number of rows and columns of the array: "); 
    int row = s.nextInt(); //row variable
    int column = s.nextInt(); //column variable
    
    double[][] array = new double[row][column]; //declare two dimensional array
    
    //assign array contents
    System.out.println("Enter the array: ");
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        array[i][j] = s.nextDouble();
      }
    }
    int[] locate = locateLargest(array); //invoke method on array
  
    System.out.println("The location of the largest element is at (" + locate[0] + ", " + locate[1] + ")");
  }
  /**
    * locateLargest
    * Finds largets element in a two-dimensional array
  */
  public static int[] locateLargest(double[][] a) {
    int[] locate = new int[] {0,0}; //make location variable in array
    
    double max = a[0][0]; //set index 0,0 as biggest
    
    //nested foor loops to go through two dimensional array 
    for(int i = 0; i < a.length; i++) {
      for(int j = 0; j < a[i].length; j++) {
        if(a[i][j] > max) { //if location is greater than max
          locate[0] = i; //new index equals i
          locate[1] = j; //new index equals j
          max = a[i][j]; //max equals [i][j] index
        }
      }
    }
    return locate; //return index
  }  
}
