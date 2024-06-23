#include <string>
#include <vector>
#include <iostream>

using namespace std;

int time_to_num(int h, int m, int s) {
    return 3600 * h + 60 * m + s;
}
vector<int> num_to_time(int time) {
    vector<int> v;
    v.push_back(time / 3600);
    time %= 3600;
    v.push_back(time / 60);
    time %= 60;
    v.push_back(time);
    return v;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    vector<int> time(3600 * 24);
    
    //시분초를 계산해서 숫자로 변환..
    int start_time = time_to_num(h1, m1, s1);
    int end_time = time_to_num(h2, m2, s2);
    
    for(int i=0; i<3600*24-1; i++) {
        double start_h_angle, start_m_angle, start_s_angle, end_h_angle, end_m_angle, end_s_angle;
        vector<int> v = num_to_time(i);
        start_h_angle = 30 * v[0] + 0.5 * v[1] + 1/120 * v[2];
        start_m_angle = 6 * v[1] + 0.1 * v[2];
        start_s_angle = 6 * v[2];
        
        while(start_h_angle >= 360) start_h_angle -= 360;
        while(start_m_angle >= 360) start_m_angle -= 360;
        while(start_s_angle >= 360) start_s_angle -= 360;
        
        v = num_to_time(i+1);
        end_h_angle = 30 * v[0] + 0.5 * v[1] + 1/120 * v[2];
        end_m_angle = 6 * v[1] + 0.1 * v[2];
        end_s_angle = 6 * v[2];
        
        while(end_h_angle >= 360) end_h_angle -= 360;
        while(end_m_angle >= 360) end_m_angle -= 360;
        while(end_s_angle >= 360) end_s_angle -= 360;
        
        int cnt = 0;
        if (start_s_angle < start_m_angle && end_s_angle >= end_m_angle) {
            cnt++;
        } else if(start_s_angle == 354 && start_m_angle > 354) {
            cnt++;
        }
        if (start_s_angle < start_h_angle && end_s_angle >= end_h_angle) {
            cnt++;
        } else if(start_s_angle == 354 && start_h_angle > 354) {
            cnt++;
        }
        time[i+1] = cnt;
    }
    
    time[0] = time[3600*12] = 1; //0시 or 12시 정각
    if(start_time == 0 || start_time == 43200) answer++;
    for(int i=start_time+1; i<=end_time; i++)
        answer += time[i];
    
    return answer;
}
