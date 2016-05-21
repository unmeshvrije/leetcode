class Queue {
    stack<int> main;
    stack<int> temp;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if (main.empty()) {
            main.push(x);
            return;
        } 
        
        while (!main.empty()) {
            temp.push(main.top());
            main.pop();
        }
        
        main.push(x);
        while (!temp.empty()) {
            main.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        main.pop();
    }

    // Get the front element.
    int peek(void) {
        return main.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return main.empty();
    }
};