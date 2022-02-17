class Solution {
public:
    
    int table(char c){
        switch(c){
            case('I'):
                return 1;
            case('V'):
                return 5;
            case('X'):
                return 10;
            case('L'):
                return 50;
            case('C'):
                return 100;
            case('D'):
                return 500;
            case('M'):
                return 1000;
            default:
                return 0;
        }
    }
    
    int romanToInt(string s) {
      
      int result = 0;  
      int i = 0;
      for(; i < s.size()-1; i++ ){
          
//     if IV OR XL OR XC OR CD OR CM
//     THEN subtract else add s[i]
        
          if( table(s[i]) >= table(s[i+1])){
              result += table(s[i]);
          } else {
              result -= table(s[i]);
          }
      }
        result += table(s[i]);
    
     return result;   
        
    }
};
