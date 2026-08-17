class Solution {
public:
    bool isPalindrome(string s) {
        int count_forward = 0;
        int count_backward = s.size()-1;
        
        while(count_forward <= count_backward){
            if(!isalnum(s.at(count_forward)) || !isalnum(s.at(count_backward))){
                if(!isalnum(s.at(count_forward)))
                    count_forward++;
                if(!isalnum(s.at(count_backward)))
                    count_backward--;
            }

            else{
                if(tolower(s.at(count_forward)) != tolower(s.at(count_backward)))
                    return false;
                cout<< s.at(count_forward) << " " << s.at(count_backward) << endl;
                count_forward++;
                count_backward--;
            }
        } 
        return true;
    }
};
