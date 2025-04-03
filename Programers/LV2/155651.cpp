// 호텔 대실
// https://school.programmers.co.kr/learn/courses/30/lessons/155651
//  reference : https://bonnate.tistory.com/499
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int covertTimeToInt(string s)
{
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int solution(vector<vector<string>> book_time)
{
    int answer = 0;
    vector<pair<int, int>> v;

    // 입실,퇴실 시간 변환
    for (vector<string> s : book_time)
    {
        v.push_back({covertTimeToInt(s[0]), covertTimeToInt(s[1]) + 10});
    }

    sort(v.begin(), v.end());

    priority_queue<int> q; // 퇴실 큐

    for (int i = 0; i < v.size(); i++)
    {
        // 큐에서 입실시간이 가장 먼저 퇴실하는 방보다 클 경우
        if (!q.empty() && -q.top() <= v[i].first)
        {
            q.pop(); // 기존 방 사용
        }

        q.push(-v[i].second);
    }

    return q.size();
}