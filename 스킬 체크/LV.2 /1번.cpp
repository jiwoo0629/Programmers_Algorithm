/*
n명의 사람이 일렬로 줄을 서고 있습니다. n명의 사람들에게는 각각 1번부터 n번까지 번호가 매겨져 있습니다. n명이 사람을 줄을 서는 방법은 여러가지 방법이 있습니다. 예를 들어서 3명의 사람이 있다면 다음과 같이 6개의 방법이 있습니다.

[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 1, 2]
[3, 2, 1]
사람의 수 n과, 자연수 k가 주어질 때, 사람을 나열 하는 방법을 사전 순으로 나열 했을 때, k번째 방법을 return하는 solution 함수를 완성해주세요.

제한사항
- n은 20이하의 자연수 입니다.
- k는 n! 이하의 자연수 입니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial[21];
vector<int> num; //사용할 숫자

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    factorial[0] = factorial[1] = 1;
    for(int i=2; i<=n; i++)
        factorial[i] = i * factorial[i-1];
    
    for(int i=0; i<n; i++)
        num.push_back(i+1);
    
    while(k > 1) {
        n--;
        int share, div;
        share = k / factorial[n];
        div = k % factorial[n];
        if(div == 0) share--;
        answer.push_back(num[share]);
        num.erase(num.begin() + share);
        k -= (share * factorial[n]);
    }   
    for(int i=0; i<num.size(); i++)
        answer.push_back(num[i]);
    
    return answer;
}
