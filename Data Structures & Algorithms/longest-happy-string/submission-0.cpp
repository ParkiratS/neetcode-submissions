class Solution {
public:
    struct CharHold{
        int count;
        char letter;

        CharHold(int c, char ch):count(c), letter(ch){}

        bool operator<(const CharHold& other) const{
            return count<other.count;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        priority_queue<CharHold> maxHeap;
        string ans = "";
        if(a>0)
            maxHeap.push(CharHold(a, 'a'));
        if(b>0)
            maxHeap.push(CharHold(b, 'b'));
        if(c>0)
            maxHeap.push(CharHold(c, 'c'));

        while(!maxHeap.empty()){
            CharHold temp = maxHeap.top();
            maxHeap.pop();

            if(ans.size() == 0 || ans.size() == 1)
                ans+=temp.letter;
            
            else{
                if(ans[ans.size()-1] == temp.letter && ans[ans.size()-2] == temp.letter){
                    if(maxHeap.empty())
                        break;
                    else{
                        CharHold temp2 = maxHeap.top();
                        maxHeap.pop();
                        ans+=temp2.letter;
                        ans+=temp.letter;
                        temp2.count--;
                        if(temp2.count>0)
                            maxHeap.push(temp2);
                    }
                }
                else
                    ans+=temp.letter;
            }
            temp.count--;
            if(temp.count>0)
                maxHeap.push(temp);
        }

        return ans;
    }
};