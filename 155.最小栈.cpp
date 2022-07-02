/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    int *data;
    short head;
    int *mindata;
    int capacity;
    void resize()
    {
        int *tmp = data, *tmpm = mindata;
        data = new int[capacity * 2], mindata = new int[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = tmp[i];
            mindata[i] = tmpm[i];
        }
        delete []tmp;
        delete []tmpm;
        capacity *= 2;
    }
public:
    MinStack() : head(-1), capacity(4){
        data = new int[capacity];
        mindata = new int[capacity];
    }
    
    void push(int x) {
        if (head == capacity - 1) 
            resize();
        data[++head] = x;
        mindata[head] = (head == 0 || x < mindata[head - 1] ? x : mindata[head - 1]);
    }
    
    void pop() {
        head--;
    }
    
    int top() {
        return data[head];
    }
    
    int getMin() {
        return mindata[head];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

