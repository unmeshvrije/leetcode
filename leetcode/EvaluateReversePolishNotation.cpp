class Operator
{
    protected:
        char oprt;
    
    public:
        virtual int compute(int a, int b) = 0;
};


class PlusOperator : public Operator
{
    public:
        PlusOperator(char oprt) {
            this->oprt = oprt;
        }
        
        int compute(int a, int b) {
            return a + b;
        }
};

class MinusOperator : public Operator
{
    public:
        MinusOperator(char oprt) {
            this->oprt = oprt;
        }
        
        int compute(int a, int b) {
            return a - b;
        }
};

class MultiplyOperator : public Operator
{
    public:
        MultiplyOperator(char oprt) {
            this->oprt = oprt;
        }
        
        int compute(int a, int b) {
            return a * b;
        }
};

class DivideOperator : public Operator
{
    public:
        DivideOperator(char oprt) {
            this->oprt = oprt;
        }
        
        int compute(int a, int b) {
            if (b == 0) {
                return 0;
            }
            return a / b;
        }
};

class OperatorFactory
{
    private:
    const string operators = "+-*/";
    
    public:

    string getOperators() {
        return operators;
    }
    
    Operator* getOperator(char operation) {
        switch(operation)
        {
            case '+': return new PlusOperator(operation);
            case '-': return new MinusOperator(operation);
            case '*': return new MultiplyOperator(operation);
            case '/': return new DivideOperator(operation); 
            default: return NULL;
        }
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        OperatorFactory of;
        string operators = of.getOperators();
        Operator *op;
        for (int i = 0; i < tokens.size(); ++i) {
            
            if (operators.find(tokens[i]) != string::npos) {
                // Get operator
                
                op = of.getOperator(tokens[i][0]);
                if (NULL == op) {
                    cerr << "Unsupported operator" << endl;
                }
                // Get operands
                int right = operands.top(); operands.pop();
                int left  = operands.top(); operands.pop();
                
                // Execute operation
                int result = op->compute(left, right);
                
                // Push the result on the stack
                operands.push(result);
            } else {
                int operand;
                stringstream ss(tokens[i]);
                ss >> operand;
                operands.push(operand);
            }
        }
        
        return operands.top();
    }
};