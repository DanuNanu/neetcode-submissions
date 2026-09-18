class Solution {
public:
    //Given temparatues: array where temparatures[i] is the temp on the 
    //ith day
    // need to return result: array where result[i] is the number of days after the ith day before a warmer temp appears
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> cache;
        for (int i = 0; i < temperatures.size(); i++) {
            //index[temperatures[i]].push(i); // maps value to index of thing being pushed
            while(!cache.empty() && temperatures[cache.top()] < temperatures[i]) {
                int ind = cache.top(); 
                cache.pop();
                result[ind] = i - ind; 
            }
            cache.push(i); // putting new top on the top of the stack
        }
        return result;
        
    }
};
