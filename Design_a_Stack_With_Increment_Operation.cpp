class CustomStack {
public:
    //Brute force Approach
    vector<int> st;
    int n = 0;
    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if (st.size() < n) {
            st.push_back(x);
        }
    }

    int pop() {
        if (st.size() != 0) {
            int ans = st.back() ;
            st.pop_back();
            return ans;
        } else {
            return -1;
        }
    }

    void increment(int k, int val) {
        if()
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
