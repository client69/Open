class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      stack <int> stack;
      int second =  -2147483648;
      for (int i = nums.size() - 1; i >= 0; i--) {
          if (nums [i] < second)
              return true;
          while (stack.size() >0 && nums [i] > stack.top()){
              second = stack.top ();
              stack.pop();
          }

          stack.push (nums [i]);
      }
      return false;
    }
};