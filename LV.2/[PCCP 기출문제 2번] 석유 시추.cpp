#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool vis[501][501];
int result[501];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int n = land.size(), m = land[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int min_y = j, max_y = j, sum = 0;
            if(vis[i][j] || land[i][j] == 0) continue;
            q.push({i, j});
            vis[i][j] = true;
            sum++;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || land[nx][ny] == 0) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    sum++;
                    min_y = min(min_y, ny);
                    max_y = max(max_y, ny);
                }
            }
            for(int k=min_y; k<=max_y; k++)
                result[k] += sum;
        }
    }
    answer = *max_element(result, result+m);
    
    return answer;
}
