import java.io.*;
import java.util.ArrayList;

class WriteToFile {
    private File file=new File("D:\\Users.txt");

    void fileWrite(ArrayList<SignUp> al,SignUp signUp) throws IOException, ClassNotFoundException {
        FileOutputStream fos=new FileOutputStream(file);
        ObjectOutputStream oos=new ObjectOutputStream(fos);
        al.add(signUp);
        oos.writeObject(al);
        oos.close();
        fos.close();
    }

    void writeSingle(SignUp signUp) throws IOException {
        FileOutputStream fos=new FileOutputStream(file);
        ObjectOutputStream oos=new ObjectOutputStream(fos);
        ArrayList<SignUp> signUps=new ArrayList<SignUp>();
        signUps.add(signUp);
        oos.writeObject(signUps);
        oos.close();
        fos.close();
    }

    ArrayList<SignUp> readFile() throws IOException, ClassNotFoundException {
       ArrayList<SignUp> signUps;
       FileInputStream fis=new FileInputStream(file);
       ObjectInputStream obis=new ObjectInputStream(fis);
       signUps=(ArrayList<SignUp>)obis.readObject();
       obis.close();
       fis.close();
       return signUps;
    }

    void fileWrite(ArrayList<SignUp> al,SignUp signUp,int index) throws IOException, ClassNotFoundException {
        FileOutputStream fos=new FileOutputStream(file);
        ObjectOutputStream oos=new ObjectOutputStream(fos);
        al.remove(index);
        al.add(index,signUp);
        oos.writeObject(al);
        oos.close();
        fos.close();
    }

    void fileWrite(ArrayList<SignUp> al,SignUp signUp,String emailId) throws IOException {
        FileOutputStream fos=new FileOutputStream(file);
        ObjectOutputStream oos=new ObjectOutputStream(fos);
        for(int i=0;i<al.size();i++){
            if(al.get(i).getEmail().equals(emailId)){
                al.remove(i);
                al.add(i,signUp);
            }
        }
        oos.writeObject(al);
        oos.close();
        fos.close();
    }
}
