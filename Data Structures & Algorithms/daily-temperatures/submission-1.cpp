class Solution {
public:
    //Given temparatues: array where temparatures[i] is the temp on the 
    //ith day
    // need to return result: array where result[i] is the number of days after the ith day before a warmer temp appears
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unordered_map<int, stack<int> > index;
        vector<int> result(temperatures.size(), 0);
        stack<int> cache;
        for (int i = 0; i < temperatures.size(); i++) {
            index[temperatures[i]].push(i); // maps value to index of thing being pushed
            while(!cache.empty() && cache.top() < temperatures[i]) {
                int temp = cache.top(); // gets the value about to be popped from the monotomic stack
                cache.pop();
                int ind = index[temp].top(); // this is the index to be looked at for the value removed
                index[temp].pop(); // remove it from the map
                result[ind] = i - ind; //calculating how long it was there for 
            }
            cache.push(temperatures[i]); // putting new top on the top of the stack
        }
        return result;
        
    }
};
