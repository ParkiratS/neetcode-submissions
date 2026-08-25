int counter = 0;

class Twitter {
public:
    unordered_map<int, queue<pair<int, int>>> tweet_map;
    unordered_map<int, unordered_set<int>> follow_map;

    Twitter() {}

    struct comp{
        bool operator()(const pair<int, int>& curr, const pair<int, int>& other) const {
            return curr.second > other.second;
        }
    };
    
    void postTweet(int userId, int tweetId) {
        if(follow_map.find(userId) == follow_map.end()){
            follow_map[userId] = unordered_set<int>();
            follow_map[userId].insert(userId);
        }

        if(tweet_map.find(userId) == tweet_map.end())
            tweet_map[userId] = queue<pair<int, int>>();
        
        if(tweet_map[userId].size() == 10)
            tweet_map[userId].pop();

        tweet_map[userId].push({tweetId, counter});
        counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> qs;

        if(follow_map.find(userId) != follow_map.end()){
            for(const int& i:follow_map[userId]){

                if(tweet_map.find(i) != tweet_map.end()){
                    queue<pair<int, int>> temp(tweet_map[i]);
                    while(!temp.empty()){
                        qs.push_back(temp.front());
                        temp.pop();
                    }
                }

            }
        }
        sort(qs.begin(), qs.end(), comp{});
        int size = min((int)qs.size(), 10);
        vector<int> ans(size);

        for(int i{0}; i<size; i++){
            ans[i] = qs[i].first;
        }

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(follow_map.find(followerId) == follow_map.end())
            follow_map[followerId] = unordered_set<int>();
        
        follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
    }
};
