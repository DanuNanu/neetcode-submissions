class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //smallest rate, min of array
        //largest rate, max pile
        // when is valid, when hours taken is less than h
        int size = piles.size();
        vector<int> copy = piles;
        std::sort(copy.begin(), copy.end());
        int min = 1;
        int max = copy[size-1];
        while (min < max) {
            int rate = min + (max-min)/2;
            // now check validity
            int total_time = 0;
            for (int p: piles) {
                total_time += std::ceil((double)p/rate);
            }
            //now bsearch part
            if (total_time > h) {
                min = rate+1;
            } else {
                max = rate;
            }

        }
        return min;
        
    }
};
