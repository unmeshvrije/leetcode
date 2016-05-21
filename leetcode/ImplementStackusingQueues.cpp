/**
 * Using two queues is much more elegant solution.
 * Alternatively push in q1 and q2.
 * 
*/

class Stack {
    queue<int> q;
    int size;
public:

    Stack() {
        size = 0;
    }
    
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        ++size;
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = size -1;
        while (n--) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
        --size;
    }

    // Get the top element.
    int top() {
        int n = size;
        int temp = -1;
        while (n--) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        return temp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return size == 0;
    }
};