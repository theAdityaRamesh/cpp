//leetcode.com/problems/integer-to-roman/

class Solution {

    public:
    
        map<int, string> romanMap = {
        { 1, "I" },
        { 2, "II" },
        { 3, "III" },
        { 4, "IV" },
        { 5, "V" },
        { 6, "VI" },
        { 7, "VII" },
        { 8, "VIII" },
        { 9, "IX" },
        { 10, "X" },
        { 40, "XL" },
        { 50, "L" },
        { 90, "XC" },
        { 100, "C" },
        { 400, "CD" },
        { 500, "D" },
        { 900, "CM" },
        { 1000, "M" }
    };

    string repeatString(string s, int reps){
        if(reps == 0) {return "";}
        reps -= 1;string temp = s;while(reps > 0){s += temp;reps -= 1;}return s;}
    
    string getRoman(int digit, int pv){
        
        if(digit == 0){
            return "";
        }
        
        string str = "";
        
        if(pv == 1){
            return romanMap[digit];
        } 
        
        else if (pv == 10){
            
            if(digit == 4){return  romanMap[40];} 
            if (digit == 9){return  romanMap[90];}
            // #50
            if(digit >= 5) {str += romanMap[50]; digit -= 5; }
            // # 10
            str +=  repeatString(romanMap[10], digit);

            return str;
        }
        
        else if (pv == 100){
            
            if(digit == 4){return romanMap[400];}
            if (digit == 9){return romanMap[900];}            
            if(digit >= 5){ str += romanMap[500]; digit -= 5;}
            
            str += repeatString(romanMap[100], digit);
            return str;
            }
        
        str = repeatString(romanMap[1000],digit) + str;
        return str;
    }
   
    string intToRoman(int num) {
        
        
        string roman = "";
        int currDigit = 0;
        int placeValue = 1;
        
        while(num>0){
            currDigit = num%10;
            roman = getRoman(currDigit, placeValue) + roman;
            placeValue *= 10;
            num = num/10;
        }
        
        return roman;
        
    }
};

// class Solution {

//     public:
//     string intToRoman(int num) {
//         string ans;
//         map<int,string>mp;
//          mp[1]='I';
//          mp[2]="II";
//          mp[3]="III";
//          mp[4]="IV";
//          mp[5]="V";
//          mp[6]="VI";
//          mp[7]="VII";
//          mp[8]="VIII";
//          mp[9]="IX";
//          mp[10]="X";
//          mp[40]="XL";
//          mp[50]="L";
//          mp[90]="XC";
//          mp[100]="C";
//          mp[400]="CD";
//          mp[500]="D";
//          mp[900]="CM";
//          mp[1000]="M";
        
//         for (auto it = mp.rbegin(); it != mp.rend(); ++it){
//             cout << it->first << endl;
//             while(num >= it->first){
//                 cout << it->first << " ";
//                 ans+= it->second;
//                 num= num - it->first;
//             }
//         }
        
//         return ans;
            
     
//     }
// };
