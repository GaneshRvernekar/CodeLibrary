// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.


class Solution {
public:

    bool check(string str)
    {
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='+' || str[i]=='-' || str[i]=='*')
                {
                    return false;
                }
        }
        return true;
    }

    vector<int> diffWaysToCompute(string expression) {

        vector<int> answers;

        if(check(expression))
        {
            answers.push_back(stoi(expression));
            return answers;
        }

        for(int i=0;i<expression.length();i++)
        {
            if(expression[i]=='*')
            {
                vector<int> vec1 =diffWaysToCompute(expression.substr(0,i));
                vector<int> vec2 =diffWaysToCompute(expression.substr(i+1));

                for(int i=0;i<vec1.size();i++)
                {
                    for(int j=0;j<vec2.size();j++)
                    {
                        answers.push_back(vec1[i]*vec2[j]);
                    }
                }
            }
            else if(expression[i]=='-')
            {
                vector<int> vec1 =diffWaysToCompute(expression.substr(0,i));
                vector<int> vec2 =diffWaysToCompute(expression.substr(i+1));

                for(int i=0;i<vec1.size();i++)
                {
                    for(int j=0;j<vec2.size();j++)
                    {
                        answers.push_back(vec1[i]-vec2[j]);
                    }
                }
            }
            else if( expression[i]=='+')
            {
                vector<int> vec1 =diffWaysToCompute(expression.substr(0,i));
                vector<int> vec2 =diffWaysToCompute(expression.substr(i+1));

                for(int i=0;i<vec1.size();i++)
                {
                    for(int j=0;j<vec2.size();j++)
                    {
                        answers.push_back(vec1[i]+vec2[j]);
                    }
                }
            }
        }

        return answers;
        
    }
};
