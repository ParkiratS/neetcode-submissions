class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int> store;
        int sum = 0;

        for(string& s:operations){
            if(s == "+"){
                sum+=store[store.size()-2] + store[store.size()-1];
                store.push_back(store[store.size()-2] + store[store.size()-1]);
            }
            else if(s == "D"){
                sum+=store[store.size()-1]*2;
                store.push_back(store[store.size()-1]*2);
            }
            else if(s == "C"){
                sum-=store[store.size()-1];
                store.pop_back();
            }
            else{
                sum+=stoi(s);
                store.push_back(stoi(s));
            }

        }

        return sum;
        
    }
};