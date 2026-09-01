class Solution {
public:

    struct Itinerary{

        int src;
        int price;
        int stops;

        Itinerary(int price, int stops, int src){
            this->price = price;
            this->stops = stops;
            this->src = src;
        }

        bool operator<(const Itinerary& other) const{
            return price > other.price;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> m(n);
        priority_queue<Itinerary> minHeap;
        vector<vector<int>> best(n, vector<int>(k + 2, INT_MAX));


        for(const auto& f:flights)
            m[f[0]].push_back({f[1], f[2]});

        minHeap.push(Itinerary(0,0, src));

        while(!minHeap.empty()){
            Itinerary temp = minHeap.top();
            minHeap.pop();

            if(best[temp.src][temp.stops] <= temp.price)
                continue;

            if(temp.src == dst)
                return temp.price;

            if(temp.stops > k)
                continue;
            

            for(const auto& f:m[temp.src]){

                int t_stops = temp.stops;
                if(f.first != dst)
                    t_stops++;

                minHeap.push(Itinerary(temp.price+f.second, t_stops, f.first));
            }

            best[temp.src][temp.stops] = temp.price;
        }

        return -1;
        
    }
};
