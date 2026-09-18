class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int width = 0;
        int height = 0;
        int area = 0;

        while (left < right) {
            height = min(heights[left], heights[right]);
            width = right-left;
            int temp_area = height*width;
            if (temp_area > area)
                area = temp_area;
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
            
            
        }
        return area;
    }
};
