public class minimumTimeToFinishJob {

    static int getMax(int arr[], int n){
    int result = arr[0];
    for (int i=1; i<n; i++)
        if (arr[i] > result)
            result = arr[i];
        return result;
    }
  
    static boolean isPossible(int time, int K, int job[], int n){
     
        int cnt = 1;
      
        int curr_time = 0; 
      
        for (int i = 0; i < n;)
        {
       
            if (curr_time + job[i] > time) {
                curr_time = 0;
                cnt++;
            }
        
            else 
            {
                curr_time += job[i];
                i++;
            }
        }
      
        return (cnt <= K);
    }

    static int findMinTime(int K, int T, int job[], int n) {
      
        int end = 0, start = 0;
        for (int i = 0; i < n; ++i)
            end += job[i];
              
       
        int ans = end; 
      
        int job_max = getMax(job, n);
     
        while (start <= end)
        {
            int mid = (start + end) / 2;
      
            if (mid >= job_max && isPossible(mid, K, job, n))
            {
     
                ans = Math.min(ans, mid); 
                  
                end = mid - 1;
            }
  
            else
                start = mid + 1;
        }
      
        return (ans * T);
    }
    public static void main(String[] args){
        int job[] = {10, 7, 8, 12, 6, 8};
        int n = job.length;
        int k = 4, T = 5;
        System.out.println(findMinTime(k, T, job, n));
    }
}
