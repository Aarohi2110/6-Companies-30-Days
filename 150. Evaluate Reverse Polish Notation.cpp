class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int op1,op2;
        stack<string> s;
        for (string i: tokens){
            if(i=="+"||i=="-"||i=="*"||i=="/")
            {
                op2=stoi(s.top());
                s.pop();
                op1=stoi(s.top());
                s.pop();
                if(i=="+")
                    s.push(to_string(op1+op2));
                else if(i=="-")
                    s.push(to_string(op1-op2));
                else if(i=="*")
                    s.push(to_string(op1*op2));
                else
                    s.push(to_string(op1/op2));   
            }
            else
                {
                    s.push(i);
                }
        }
       return stoi(s.top());
    }
};
