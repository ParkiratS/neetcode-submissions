class Solution {
public:

    vector<int> mergeSort(vector<string>& names, vector<int>& heights, int l, int r){
        if(l>=r)
            return {r};
        
        int mid = (l + r)/2;
        vector<int> left = mergeSort(names, heights, l, mid);
        vector<int> right = mergeSort(names, heights, mid+1, r);
        vector<int> curr(left.size()+right.size());

        int i = 0, j = 0;

        while(i<left.size() || j<right.size()){
            if(i == left.size()){
                curr[i+j] = right[j];
                j++;
            }

            else if(j == right.size()){
                curr[i+j] = left[i];
                i++;
            }
            else{
                if(heights[left[i]] > heights[right[j]]){
                    curr[i+j] = left[i];
                    i++;
                }
                else{
                    curr[i+j] = right[j];
                    j++;
                }
            }
        }

        return curr;

    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> ind = mergeSort(names, heights, 0, heights.size()-1);
        vector<string> ans;

        for(int& i:ind){
            ans.push_back(names[i]);
        }

        return ans;
        
    }
};