import javax.swing.JOptionPane;
public class RandomGuess4
{
   public static void main(String[] args)
   {
      int guess = 0; 
      int result; 
      String msg;
      int attempts = 1;
      final int LOW = 1; 
      final int HIGH = 10; 
      boolean ok = false; 
      result = LOW + (int)(Math.random() * HIGH);
      while(!ok)
      {
         try
         {
            guess = Integer.parseInt(JOptionPane.showInputDialog(null, "Try to guess my number between " + LOW + " and " + HIGH));
            ok = true; 
            }
            catch(NumberFormatException e)
            {
               JOptionPane.showMessageDialog(null, "Input must be a number");
               ok = false; 
               }
            }
            while(guess != result)
            {
            if(guess < result)
              msg = "Your guess was too low";
              else
              msg = "Your guess was too high";
              guess = Integer.parseInt(JOptionPane.showInputDialog(null, msg + "\nGuess again"));
              ++attempts;
              }
              JOptionPane.showMessageDialog(null, "Correct! You got it in " + attempts + " attempts");
              }
            }