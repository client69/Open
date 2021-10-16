import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PasswordField {
    static String readPassword(String prompt)
    {
        EraserThread et = new EraserThread();
        Thread mask = new Thread(et);
        // mask.setPriority(5);
        mask.start();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String password = "";
        System.out.print(prompt);
        try
        {
            password += in.readLine();
            // System.out.print(password);
        }
        catch (IOException ioe)
        {
            ioe.printStackTrace();
        }
        et.stopMasking();
        // System.out.println(password);
        return password;
    }
}
