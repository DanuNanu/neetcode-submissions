class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //plan have one vector that counts the number of zeros
        //if more than one zero appears then immediately return a vector filled with zeros
        //otherwise if one zero appears then do the product static calculation and fill everything but 
        //that one till zero

        //mathematics behind it
        //if build map and put the product for everything but current 
        // so at i+1 iteration map[i] = 1*2*...*i-1, map[i+1] = 1*2*...*i 
        //prefix suffix technque
        //for i and i+1
        //i prefx = 1*2*...*(i-1), (i+1) = 1*2...*i
        //i suffix = (i+1)*...*n, (i+1) suffix = (i+2)*...*n
        // nth element's product is its prefix, 1st element product is its suffix
         vector<int> prefix(nums.size(),1);

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i-1]*prefix[i-1];
        }
        int multip = 1;
        for (int j = (nums.size()-2); j >=0; j--) {
            if (j == (nums.size()-2)) {
                prefix[j] = prefix[j]*nums[nums.size()-1];
                multip = nums[j]*nums[nums.size()-1];
            } else {
            prefix[j] = prefix[j]*multip;
            multip = nums[j]*multip;
            //suffix[j] = nums[j+1]*suffix[j+1];
            //result[j] =prefix[j]*suffix[j];
            }
        }
        return prefix;



    }
};
