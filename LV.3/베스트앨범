#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    for(int i=0; i<genres.size(); i++) {
        if(m[genres[i]] == 0) m[genres[i]] = plays[i];
        else m[genres[i]] += plays[i];
    }
    vector<pair<string, int>> v; //장르별 총 금액 정렬
    for(auto it=m.begin(); it!=m.end(); it++) v.push_back({it->first, it->second});
    stable_sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) {
        string genre = v[i].first;
        vector<pair<int, int>> v2; //(순서, 가격) 
        for(int j=0; j<genres.size(); j++) 
            if(genres[j].compare(genre) == 0) v2.push_back({j, plays[j]});
        stable_sort(v2.begin(), v2.end(), cmp2); //가격 순 정렬
        if(v2.size() < 2)
            for(int j=0; j<v2.size(); j++) answer.push_back(v2[j].first);
        else 
            for(int j=0; j<2; j++) answer.push_back(v2[j].first);
    }
    
    return answer;
}
