class Solution {
public:
    
    int maxArea(vector<int>& height) {
        
        int left = 0,
            right = height.size()-1,
            maxArea = 0;
        
       while(left < right){
           
              maxArea = max((right-left)*min(height[right],height[left]), maxArea);      
              if(height[left] > height[right]){
                  right--;
              } else { left++;}
       }
        return maxArea;
    }
};
