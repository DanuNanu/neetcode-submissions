class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //smallest rate, min of array
        //largest rate, max pile
        // when is valid, when hours taken is less than h
        int size = piles.size();
        int max = *std::max_element(piles.begin(), piles.end());
        int min = 1;
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
