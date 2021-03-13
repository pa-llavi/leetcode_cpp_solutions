class CustomStack {
public:
    vector<int> vec;
    int max_size;
    CustomStack(int maxSize) {
        max_size = maxSize;
    }
    
    void push(int x) {
        if(vec.size() < max_size)
            vec.push_back(x);
    }
    
    int pop() {
        int val= -1;
        if(vec.size()>0)
        {
            val = vec[vec.size()-1];
            vec.erase(vec.begin()+vec.size()-1);
        }
        return val;
    }
    
    void increment(int k, int val) {
        int increment_count;
        increment_count = (k>=vec.size()? vec.size() : k);
        for(int i=0; i<increment_count; i++)
            vec[i] = vec[i]+val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
