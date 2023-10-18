class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>sys;
        stack<char>temp;
        for(auto &it:expression){
            if(it!=')' && it!=','){
                sys.push(it);
            }
            else if(it==')'){
                while(sys.top()!='('){
                    temp.push(sys.top());
                    sys.pop();
                }
                sys.pop();
                if(sys.top()=='!'){
                    sys.pop();
                    while(temp.size()){
                        if(temp.top()=='f') sys.push('t');
                        else sys.push('f');
                        temp.pop();
                    }
                }
                else if(sys.top()=='&'){
                    sys.pop();
                    char p=temp.top();
                    temp.pop();
                    while(temp.size()){
                        if(p=='t'){
                            if(temp.top()=='t'){
                                temp.pop();
                                p='t';
                            }
                            else{
                                p='f';
                                while(temp.size()) temp.pop();
                            }
                        }
                        else while(temp.size()) temp.pop();
                    }
                    sys.push(p);
                }
                else if(sys.top()='|'){
                    sys.pop();
                    char p=temp.top();
                    temp.pop();
                    while(temp.size()){
                        if(p=='f'){
                            if(temp.top()=='f'){
                                temp.pop();
                                p='f';
                            }
                            else{
                                p='t';
                                while(temp.size()) temp.pop();
                            }
                        }
                        else while(temp.size()) temp.pop();
                    }
                    sys.push(p);
                }
            }
            cout<<sys.top()<<" ";
        }
        return (sys.top()=='t')?true:false;
    }
};