class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target){
        int i1 = -1, i2 = -1, i3 = -1;

        for(int i{0}; i<triplets.size(); i++){
            vector<int>& temp = triplets[i];
            if(temp[0] == target[0] && temp[1] <= target[1] && temp[2] <= target[2])
                i1 = i;

            if(temp[1] == target[1] && temp[0] <= target[0] && temp[2] <= target[2])
                i2 = i;
            
            if(temp[2] == target[2] && temp[0] <= target[0] && temp[1] <= target[1])
                i3 = i;
            
        }

        return (i1 != -1 && i2 != -1 && i3 != -1);
    }
};
