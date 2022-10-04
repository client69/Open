import javax.swing.*;
class MeanMedian2
{
   public static void main(String[] args)
   {
      int[] nums = new int[20];
      int num = 0;
      String entry;
      String list = "You entered: ";
      int a, b;
      int temp;
      double median;
      int total = 0;
      double mean = 0;
      final int QUIT = 9999;
      int size = 0;
      for(a = 0; num != QUIT && a < nums.length; ++a)
      {
         entry = JOptionPane.showInputDialog(null,
           "Enter number " + (a + 1) + " or " + QUIT + " to quit");
         num = Integer.parseInt(entry);
         if(num != QUIT)
         {
            nums[a] = num;
            total += nums[a];
            if(a == 0)
               list += nums[a];
            else
               list += ",  " + nums[a];
         }
      }
     System.out.println("size is " + a);
      if(num != QUIT)
         size = nums.length;
      else
         size = a - 1;
      System.out.println("size is " + size);
 System.out.println(list);
      int comparisonsToMake = size - 1;
      for(a = 0; a < size - 1; ++a)
      {
         for(b = 0; b < comparisonsToMake; ++b)
         {
            if(nums[b] > nums[b + 1])
            {
               temp = nums[b];
               nums[b] = nums[b + 1];
               nums[b + 1] = temp;
            }
         }
         --comparisonsToMake;
      }
      if(size % 2 == 0)
         median = (nums[(size / 2)] + nums[size / 2 - 1]) / 2.0;
      else
         median = nums[size / 2] / 1.0;
      if(size != 0)
        mean = total * 1.0 / size;
      System.out.println("The mean is " + mean +
         " and the median is " + median);

   }
}
   