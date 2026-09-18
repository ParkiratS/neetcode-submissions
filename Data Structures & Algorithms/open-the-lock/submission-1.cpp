class Solution {
public:
    struct Combination{
        string s;
        int count;

        Combination(string temp, int c): s(temp), count(c){}
    };

    string moveUp(string s, int i, unordered_set<string>& seen){
        char temp;
        if(s[i] == '9')
            temp = '0';

        else
            temp = s[i]+1;
        
        s[i] = temp;
        if(seen.find(s) != seen.end())
            return "";
        seen.insert(s); 
        return s;
    }

string moveDown(string s, int i, unordered_set<string>& seen){
    char temp;
    if(s[i] == '0')
        temp = '9';

    else
        temp = s[i]-1;
    
    s[i] = temp;
    if(seen.find(s) != seen.end())
        return "";
    seen.insert(s); 
    return s;
}

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> seen;
        queue<Combination> q;

        if("0000" == target)
            return 0;

        for(string str:deadends)
            seen.insert(str);

        if(seen.find("0000") == seen.end()){
            q.push(Combination("0000", 0));
            seen.insert("0000");
        }

        while(!q.empty()){
            string temp;
            Combination t = q.front();
            q.pop();

            int count = t.count+1;

            for(int i{0}; i<4; i++){
                temp = moveUp(t.s, i, seen);
                if(temp == target)
                    return count;
                if(temp != "")
                    q.push(Combination(temp, count));

                temp = moveDown(t.s, i, seen);
                if(temp == target)
                    return count;
                if(temp != "")
                    q.push(Combination(temp, count));

            }
        }

        return -1;
        
    }
};