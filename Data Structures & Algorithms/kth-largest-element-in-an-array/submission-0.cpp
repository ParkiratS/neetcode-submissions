vector<int> mergeSort(vector<int> nums){
    if(nums.size() == 1)
        return nums;

    if(nums.size() == 0)
        return {};

    vector<int> ans;
    auto mid = nums.begin() + nums.size() / 2;

    vector<int> v1(nums.begin(), mid);
    vector<int> v2(mid, nums.end());

    vector<int> o1 = mergeSort(v1);
    vector<int> o2 = mergeSort(v2);

    int s1 = o1.size(), s2 = o2.size();
    int i = 0, j = 0;

    while(i < s1 || j < s2){
        if(i < s1 && j < s2){
            if(o1[i] <= o2[j]){
                ans.push_back(o1[i]);
                i++;
            }
            else{
                ans.push_back(o2[j]);
                j++;
            }
        }

        else if(i==s1){
            ans.push_back(o2[j]);
            j++;
        }

        else{
            ans.push_back(o1[i]);
                i++;
        }
    }

    return ans;
}

class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> ans = mergeSort(nums);


        for(int i: ans)
            cout<<i<<endl;
        
        return ans[ans.size()-k];
    }
};
