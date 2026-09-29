class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int left = 0, right = people.size()-1;
        int count = 0;

        while(left <= right){
            if(right == left ){
                left++;
                right--;
            }
            
            else if(people[right] == limit || people[right] + people[left] > limit)
                right--;
            
            else{
                left++;
                right--;
            }

            count++;

        }

        return count;

        
    }
};