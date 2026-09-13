class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {


        int sum = 0, m = weights[0];
        for(int& i:weights){
            sum+=i;
            m = max(m, i);
        }

        int left = m, right = sum, ans = sum;

        while(left<=right){

            int middle = (left + right)/2;

            int count = 1, curr = 0;
            for(int& i:weights){
                if(i+curr > middle){
                    count++;
                    curr = i;
                }
                else
                    curr+=i;
            }

            if(count <= days){
                ans = min(ans, middle);
                right = middle-1;
            }
            else
                left = middle+1;
        }

        return ans;
    }
};