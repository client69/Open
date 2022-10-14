class Solution {
public:
    bool checkValidString(string s) {
      stack<int> sb, ss;
      for(auto i=0; i<s.size(); ++i){
        char ch = s[i];
        if(ch=='(') sb.push(i);
        else if(ch=='*') ss.push(i);
        else {
          if(!sb.empty()) sb.pop();
          else if(!ss.empty()) ss.pop();
          else return false;
        }
      }
      
      
      while(sb.size() && ss.size()){
        if(ss.top() > sb.top()){
          ss.pop(); sb.pop();
        } else break;
      }
      
      if(sb.size()) return false;
      return true;
    }
};