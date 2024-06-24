/*
다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

(), [], {} 는 모두 올바른 괄호 문자열입니다.
만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.
만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.
대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
- s의 길이는 1 이상 1,000 이하입니다.
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    stack<char> st;
    int t = s.size();
    while(t--) {
        char c = s[0];
        s = s.substr(1, s.size()-1);
        s += c;
        bool correct = true;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if(st.empty()) {
                    correct = false;
                    continue;
                }
                if(s[i] == ')') { 
                    if(st.top() == '(') st.pop();
                    else {
                        correct = false;
                        continue;
                    }
                }
                if(s[i] == '}') {
                    if(st.top() == '{') st.pop();
                    else {
                        correct = false;
                        continue;
                    }
                }
                if(s[i] == ']') {
                    if(st.top() == '[') st.pop();
                    else {
                        correct = false;
                        continue;
                    }
                }
            }
        }
        if(!st.empty()) {
            correct = false;
            while(!st.empty())
                st.pop();
        }
        if(correct) answer++;
    }
    
    return answer;
}
