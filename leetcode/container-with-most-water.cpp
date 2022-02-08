class Solution {
public:
    
    int maxArea(vector<int>& height) {
        
        int left = 0,
            right = height.size()-1,
            area = 0,
            minHeight = min(height[left],height[right]),
            maxArea = (right-left)*minHeight;
        
       while(left < right){
   
            if(height[left] > height[right]){
                while(height[right] <= minHeight && right > 0){
                    right--;
                }
                
                area = (right-left)*min(height[right],height[left]);
                if(maxArea < area){
                    maxArea = area;
                }
                
            } else {
                while(height[left] <= minHeight && left < height.size()-1){
                    left++;
                }
                
                area = (right-left)*min(height[right],height[left]);
                if(maxArea < area){
                    maxArea = area;
                }
                
            }
           minHeight = min(height[left],height[right]);
       }
        return maxArea;
    }
};
