/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    std::stack<int> insack, outstack;
public:
    MyQueue() {

    }
    
    void push(int x) {
        insack.push(x);
    }
    
    int pop() {
        int rev = peek();
        outstack.pop();
        return rev;
    }
    
    int peek() {
        if(outstack.empty())
        {
            while(!insack.empty())
            {
                outstack.push(insack.top());
                insack.pop();
            }
        }
        return outstack.top();
    }
    
    bool empty() {
        if(insack.empty() && outstack.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

