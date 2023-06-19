#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> c;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') c.push('(');
        else if(s[i] == ')') {
            if(c.empty()) {
                return false;
                break;
            }
            else c.pop();
        }
    }
    if(c.empty()) answer = true;
    else answer = false;

    return answer;
}
