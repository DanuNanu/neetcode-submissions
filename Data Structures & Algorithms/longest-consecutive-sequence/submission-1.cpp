class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (int num: nums) {
            hash.insert(num);
        }
        int longest = 0;
        for (int num: nums) {
            if (!hash.count(num-1)) {
                int length =1;
                while (hash.count(num+length)) {
                    length +=1;
                }
                if (length > longest) {
                    longest = length;
                }
            }
        }
        return longest;
    }
};
