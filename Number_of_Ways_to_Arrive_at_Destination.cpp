class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long,long long>, 
                                                vector<pair<long long, long long>>, greater<pair<long long,long long>>> pq;
        vector<long long> dist(n, LLONG_MAX); //To store the min Dist
        vector<long long int> ways(n,0); //To store the number of ways it can reach

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0}); //Inserting the source node

        int mod = 1e9 + 7;

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                long long edW = it.second;

                if( dis + edW < dist[adjNode]){
                    dist[adjNode] = dis+edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+edW == dist[adjNode]){
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
