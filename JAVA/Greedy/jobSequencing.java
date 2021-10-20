import java.io.*;
import java.util.*;



public class jobSequencing{

    // Driver code
    static class Job 
    {
        // Each job has a unique-id,
        // profit and deadline
        char id;
        int deadline, profit;
      
        // Constructors
        public Job() {}
      
        public Job(char id, int deadline, int profit)
        {
            this.id = id;
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        Arrays.sort(jobs, Comparator.comparingInt(a -> a[1]));
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i + 1] = Math.max(dp[i], dp[i + 1]);
            int lo = 0, hi = i;
            while(lo < hi - 1) {
                int m = lo + (hi - lo)/ 2;
                if (jobs[m][1] <= jobs[i][0]) {
                    lo = m;
                } else {
                    hi = m;
                }
            }
            dp[i + 1] = Math.max(dp[i + 1], ((jobs[lo][1] <= jobs[i][0]) ? dp[lo + 1] : 0) + jobs[i][2]);
        }
        return dp[n];
    }
    
    public static void JobSchedulingDeadline(Job[] arr, int t)
    {
       
        int n = arr.length;
  
        Arrays.sort(arr, new Comparator<Job>(){
                                    @Override 
                                    public int compare(Job a, Job b)    {
                                         return b.profit - a.profit;
                                    }
                             } );
  
        boolean result[] = new boolean[t];
  
        char job[] = new char[t];
  
        for (int i = 0; i < n; i++) 
        {
     
            for (int j
                 = Math.min(t - 1, arr[i].deadline - 1);
                 j >= 0; j--) {
  
                // Free slot found
                if (result[j] == false) 
                {
                    result[j] = true;
                    job[j] = arr[i].id;
                    break;
                }
            }
        }
 
        for (char jb : job) 
        {
            System.out.print(jb + " ");
        }
        System.out.println();
    }
    public static void main(String args[]) throws IOException    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        String[] str=br.readLine().trim().split(" ");
        String[] str1=br.readLine().trim().split(" ");
        String[] str2=br.readLine().trim().split(" ");
        
        int[] arr=new int[str.length];
        int[] arr1=new int[str.length];
        int[] arr2=new int[str.length];

        for(int i=0;i<str.length;i++){
            arr[i]=Integer.parseInt(str[i]);
            arr1[i]=Integer.parseInt(str1[i]);
            arr2[i]=Integer.parseInt(str2[i]);
        }

        //here job sequencing have a starting and an ending point
        System.out.println(jobScheduling(arr,arr1,arr2));

        //job sequencing with only deadline and fixed work time of 1 unit
        
    }

}
