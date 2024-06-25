#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1}; 
int n, m;
vector<string> board;
bool vis[502][502][4]; //이미 사용한 경로인지 확인

int change_direction(char c, int dir) {
    int nxt_dir;
    if(c == 'S') nxt_dir = dir;
    else if(c == 'L') {
        if(dir == 0) nxt_dir = 2; //상 -> 좌
        else if(dir == 1) nxt_dir = 3; //하 -> 우
        else if(dir == 2) nxt_dir = 1; //좌 -> 하
        else if(dir == 3) nxt_dir = 0; //우 -> 상
    }
    else if(c == 'R') {
        if(dir == 0) nxt_dir = 3; //상 -> 우
        else if(dir == 1) nxt_dir = 2; //하 -> 좌
        else if(dir == 2) nxt_dir = 0; //좌 -> 상
        else if(dir == 3) nxt_dir = 1; //우 -> 하
    }
    return nxt_dir;
}

int func(int x, int y, int dir, int len) {
    if(vis[x][y][dir]) return len;
    vis[x][y][dir] = true;
    
    int ndir = change_direction(board[x][y], dir);
    int nx = x + dx[ndir], ny = y + dy[ndir];
    if(nx < 0) nx = n-1;
    else if(nx == n) nx = 0;
    if(ny < 0) ny = m-1;
    else if(ny == m) ny = 0;
    
    return func(nx, ny, ndir, len+1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    n = grid.size(); //n: 행
    m = grid[0].size(); //m: 열
    board = grid;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                int result = func(i, j, k, 0);
                if(result != 0) answer.push_back(result);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
