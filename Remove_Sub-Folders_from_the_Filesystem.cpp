class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //Optimeal Approach
        vector<string> ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        for(int i =1;i<folder.size(); i++){
            string currFolder = folder[i];
            string lastFolder = ans.back();
            lastFolder += '/';
            if(currFolder.find(lastFolder) != 0){
                ans.push_back(currFolder);
            }
        }
        return ans;
    }
};
