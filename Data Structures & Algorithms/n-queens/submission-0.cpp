class Solution {
public:

    bool safe(int& r1, int& c1, int& r2, int& c2){
        if(c1 == c2)
            return false;
        
        if(abs(r1-r2) == abs(c1-c2))
            return false;

        return true;
    }

    void traverse(vector<vector<string>>& ans, vector<int>& ind, int& n, int index){
        if(index == n){
            vector<string> curr(n);
            string temp = "";

            for(int i{0}; i<n; i++)
                temp+='.';

            for(int i{0}; i<n; i++){
                temp[ind[i]] = 'Q';
                curr[i] = temp;
                temp[ind[i]] = '.';
            }

            ind[ind.size()-1]++;
            ans.push_back(curr);
            return;
        }

        int j = ind[index];
        bool flag = true && (j<n);

        if(index == 0 && j>= n)
            return;

        for(;j<n;j++){
            flag = true;
            for(int i{0}; i<index; i++){
                if(!safe(index, j, i, ind[i])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ind[index] = j;
                break;
            }
        }

        if(flag)
            traverse(ans, ind, n, index+1);
        else{
            ind[index] = 0;
            ind[index-1]++;
            traverse(ans, ind, n, index-1);
        }
        

        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> inds(n, 0);

        while(inds[0] < n){
            traverse(ans, inds, n, 0);
        }

        return ans;

        
    }
};
