class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //plan first find thr things that can only be the start of the sequence (dont have n-1)
        //note that the same number cannot be 2 possible sequences as then it implies that there
        //must be a number connecting the two sequences, for example, hence there can only be possible
        //start and so there cant be 2 possibilities of a seuqence

        //plan :
        //first find possible starts
        //do this by creating hash map with key being (n-1) the value
        //of the number and the value being the number itself
        

        //keep 2 lists like a linked list
        //one would be the current tail of a sequence that gives the key/pointer for the head of the list
        //the ohter is the map of the head of the list with head as key and value is the list
        //for every number check if the (n-1) is a head, if so then join it and add the number to the 
        //map for the tail of the list. Since numbers are sequential it is guarenteed that this is the current tail
        // if n-1 is a head
        //check if (n+1) is a head in case this number is a bridge, if (n+1) is a head
        //then join the value of that list to the proper (n-1) map and then update the tail
        //if (n+1) and (n-1) checks on the head map yield no results check for (n-1) in the tail list, 
        //checking for (n-1) is futile since every element in the tail list has its n-1 already known so not a possibility
        //this way keep building the list as well as only searching for heads in the necessary values in one go
        //also for duplicate numbers its ago to ignore because its not like if a  number shows up again we need to check
        //whether it does any significant checks cause the same number cant contest a list cause it cant belong in both lists

        unordered_map<int, vector<int>> head;
        unordered_map<int, int> tail;
        unordered_set<int> exists;

        int size = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (exists.find(nums[i]) != exists.end()) {
                continue;
            } else {
                exists.insert(nums[i]);
            }
            if (head.count(nums[i]-1)) {
                head[nums[i]-1].push_back(nums[i]);
                tail[nums[i]] = nums[i]-1;
                //if (n+1) has its own sequencer
                if (head.count(nums[i]+1)) {
                    for (int numb: head[nums[i]+1]) {
                        head[nums[i]-1].push_back(numb);
                    }
                    head.erase(nums[i]+1);
                    int new_tail_index = head[nums[i]-1].size()-1;
                    int new_tail = head[nums[i]-1][new_tail_index];
                    if (tail.contains(new_tail)) {
                        tail[new_tail] = (nums[i]-1); //update head of the tail
                        tail.erase(nums[i]);
                    } else { //in this case the need to update tail to the latest number
                        tail.erase(nums[i]);
                        tail[new_tail] = (nums[i]-1);
                    }
                } // if the next number is a head then update the mapping so that num[i] the new head
            } else if (tail.contains(nums[i]-1)) {
                    int head_index = tail[nums[i]-1];
                    head[head_index].push_back(nums[i]); //add it
                    //now update tail
                    tail.erase(nums[i]-1);
                    tail[nums[i]] = head_index;
                    // now that the number has been added, need to check if the next
                    //sequence is contained in the head, and if so need to join to bridge the tw
                    if (head.contains(nums[i]+1)) {
                        for (int gib: head[nums[i]+1]) {
                            head[head_index].push_back(gib);
                        }
                        head.erase(nums[i]+1);
                        int tail_index = head[head_index].size()-1;
                        int tail_value = head[head_index][tail_index];
                        //now check if tail contains the tail value or not
                        if (tail.contains(tail_value)) {
                            tail.at(tail_value)= head_index;
                            tail.erase(nums[i]);
                        } else { //otherwise still need to update
                            tail.erase(nums[i]);

                            tail[tail_value] = head_index;
                        }
                    }

                //now case when the previous number not a head, next number not a head, previous number not a tail
                // since we have the exists clause to take care of duplicates, it must be that there
                //are currently no conditions on num[i] so add a new head mapping
            } else if (head.contains(nums[i]+1)) {
                    head[nums[i]].push_back(nums[i]);
                    for (int val: head[nums[i]+1]) {
                        head[nums[i]].push_back(val);
                    } // now update tail accordingly
                    head.erase(nums[i]+1);
                    int new_tail_index = head[nums[i]].size()-1;
                    int new_tail = head[nums[i]][new_tail_index];
                    //if tail alreadu exists then just update value to reflect the head of the tail being num[i]
                    if (tail.contains(new_tail)) {
                        tail.at(new_tail) = nums[i];
                    } else { //otherwise add tail entry
                        tail[new_tail] = nums[i];
                    } 
                    // case when head does not contain either
                    // check if tail contains (num[i]-1) if so then add num[i] to the head map and update tail up
             } else {
                head[nums[i]].push_back(nums[i]);
            }
        }
        // now after the loop is over, we should be able to get the max consec seg 
        //since construction is taken care of
        int result = 0;
        int indexof = 0;
        for (const auto& pair: head) {
           if (result < pair.second.size()) {
            result = pair.second.size();
            indexof = pair.first;
           }
        }
        return result;
                
        }
            
            //n-1 check first in head
            //n

        };
    
