class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {


        int maxBananas = piles[0];

        for(int b : piles)
            maxBananas = max(b, maxBananas);

        int lB = 1, rB = maxBananas;

        while(lB<rB){
            int hours = 0, pred = (lB+rB)/2;

            for(int b : piles)
                hours += (b + pred - 1) / pred;
            
            if (hours > h)
                lB = pred + 1;
            
            else
                rB = pred;
        }

        return lB;
    }
};
