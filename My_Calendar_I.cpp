class MyCalendar {
    //Brute force TC is O(n^2) and sc is O(n)
public:
    vector<pair<int,int>>calender;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i =0; i<calender.size();i++){
            pair<int,int> curr = calender[i];
            if(curr.first < end && start <curr.second){
                return false;
            }
        }
        calender.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

