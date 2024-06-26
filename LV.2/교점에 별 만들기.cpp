#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int, int>> v;
    
    for(int i=0; i<line.size(); i++) {
        for(int j=i+1; j<line.size(); j++) {
            int a = line[i][0], b = line[i][1], e = line[i][2]; //[a1, b1, c1]
            int c = line[j][0], d = line[j][1], f = line[j][2]; //[a2, b2, c2]
            
            int divider = a*d - b*c;
            if(divider == 0) continue;
            long long x = (long long)b*f - (long long)e*d;
            long long y = (long long)e*c - (long long)a*f;
            
            if(x % divider == 0 && y % divider == 0)
                v.push_back({x / divider, y / divider});
        }
    }
    int min_x = v[0].first, min_y = v[0].second, max_x = v[0].first, max_y = v[0].second;
    for(int i=1; i<v.size(); i++) {
        min_x = min(min_x, v[i].first);
        min_y = min(min_y, v[i].second);
        max_x = max(max_x, v[i].first);
        max_y = max(max_y, v[i].second);
    }
    sort(v.begin(), v.end(), cmp);
    int idx = 0;
    for(int i=max_y; i>=min_y; i--) {
        string str = "";
        for(int j=min_x; j<=max_x; j++) {
            if(i == v[idx].second && j == v[idx].first) {
                str += '*';
                do {
                    idx++;
                    if(idx == v.size())
                        break;
                } while(i == v[idx].second && j == v[idx].first);
            }
            else
                str += '.';
        }
        answer.push_back(str);
    }
    return answer;
}
