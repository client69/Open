package rc4;

import java.util.Scanner;

import java.io.*;

class RC4 {

    public static void main(String args[]) throws IOException {
        int temp = 0;
        String ptext;
        String key;
        int s[] = new int[256];
        int k[] = new int[256];
        Scanner sc=new Scanner(System.in);
        DataInputStream in = new DataInputStream(System.in);
        System.out.println("ENTER PLAIN TEXT");
        ptext = sc.nextLine();
        System.out.println("\n");
        System.out.println("ENTER KEY");
        key = sc.nextLine();
        System.out.println("\n");
        char ptextc[] = ptext.toCharArray();
        char keyc[] = key.toCharArray();
        
        int cipher[] = new int[ptext.length()];
        int decrypt[] = new int[ptext.length()];

        int ptexti[] = new int[ptext.length()];
        int keyi[] = new int[key.length()];
        
        for (int i = 0; i < ptext.length(); i++) {
            ptexti[i] = (int) ptextc[i];
        }
        for (int i = 0; i < key.length(); i++) {
            keyi[i] = (int) keyc[i];
        }
        for (int i = 0; i < 255; i++) {
            s[i] = i;
            k[i] = keyi[i % key.length()];
        }
        int j = 0;
        for (int i = 0; i < 255; i++) {
            j = (j + s[i] + k[i]) % 256;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        for(int i=0;i<255;i++)
        {
            System.out.print(","+s[i]);
        }
         System.out.print("\n");
        int i = 0;
        j = 0;
        int z = 0;
        for (int l = 0; l < ptext.length(); l++) {
            i = (l + 1) % 256;
            j = (j + s[i]) % 256;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            z = s[(s[i] + s[j]) % 256];
            System.out.print("\t"+z);
           
            cipher[l] = z ^ ptexti[l];
            decrypt[l] = z ^ cipher[l];
        }
              
       
        System.out.print("\n");
        System.out.println("ENCRYPTED");
        display(cipher);
        System.out.println("\n");
        System.out.println("DECRYPRED");
        display(decrypt);
        System.out.println("\n");
    }

    static void display(int disp[]) {
        char convert[] = new char[disp.length];
        for (int l = 0; l < disp.length; l++) {
            convert[l] = (char) disp[l];
            System.out.print(convert[l]);
        }
    }

}
