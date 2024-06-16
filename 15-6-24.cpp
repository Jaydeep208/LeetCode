// Question: IPO (502)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //Optimised approach
        int n = profits.size();
        vector<pair<int,int>> cp;
        for(int i =0;i<n;i++){
            cp.push_back({capital[i], profits[i]});
        }
        sort(cp.begin(), cp.end());
        
        priority_queue<int> pq;

        int i =0;
        while(k--){
            while(i<n && cp[i].first <= w){
                pq.push(cp[i].second);
                i++;
            }
            if(pq.empty()){
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
