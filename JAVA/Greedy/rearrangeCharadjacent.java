import java.io.*;
import java.util.*;


public class rearrangeCharadjacent {

    static class KeyComparator implements Comparator<Key> {
    
          
            public int compare(Key k1, Key k2)
            {
                if (k1.freq < k2.freq)
                    return 1;
                else if (k1.freq > k2.freq)
                    return -1;
                return 0;
            }
    }
        
    static class Key {
            int freq; // store frequency of character
            char ch;
            Key(int val, char c) 
            {
                freq = val; 
                ch = c;
            }
    }
    public static String rearrange(String str){
        int[] charr=new int[26];
        for(char ch:str.toCharArray()){
            charr[ch-'a']++;
        }

        PriorityQueue<Key> q=new PriorityQueue<>(new KeyComparator());

        for(int i=0;i<26;i++){
            if(charr[i]>0)
                q.add(new Key(charr[i],(char)('a'+i) ));
        }

        Key prev=new Key(-1,'#');
        StringBuilder  ans=new StringBuilder();
        while (q.size() != 0) {
         
            Key k = q.peek();
            q.poll();
            ans.append(k.ch);

            if (prev.freq > 0)
                q.add(prev);

            (k.freq)--;
             prev = k;
        }

        return ans.toString();
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new  BufferedReader(new InputStreamReader(System.in));
        String str=br.readLine();
        System.out.println(rearrange(str));

    }
}
