class MinStack {
    private:
    struct StackNode {
      int data;
      int minimum;
      StackNode* next;
      StackNode(int d):data(d), minimum(d) { next = NULL;}
    };
    
    StackNode *TOP = NULL;
public:

    MinStack() {
        TOP = NULL;
    }
    
    void push(int x) {
        StackNode *newnode = new StackNode(x);
        
        if (TOP == NULL) {
            TOP = newnode;
            newnode->minimum = x;
            return;
        }
        
        if (TOP->minimum < newnode->minimum) {
            newnode->minimum = TOP->minimum;
        }
        newnode->next = TOP;
        TOP = newnode;
    }

    void pop() {
        if (TOP == NULL) {
            return;
        }
        StackNode *temp = TOP;
        TOP = TOP->next;
        delete temp;
    }

    int top() {
        if (TOP == NULL) {
            return -1;
        }
        return TOP->data;
    }

    int getMin() {
        if (TOP == NULL) {
            return -1;
        }
        return TOP->minimum;
    }
};
