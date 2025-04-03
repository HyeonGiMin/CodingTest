// 전력망을 둘로 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/86971
//  reference : https://velog.io/@slow_cosmos/c%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%A0%84%EB%A0%A5%EB%A7%9D%EC%9D%84-%EB%91%98%EB%A1%9C-%EB%82%98%EB%88%84%EA%B8%B0
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int gap(vector<vector<int>> v)
{
    vector<int> visit(v.size());
    queue<int> q;

    // v1은 1이상
    q.push(1);
    int cnt = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visit[cur] == 1)
            continue;

        visit[cur] = 1;
        cnt++;
        for (int i = 0; i < v[cur].size(); i++)
        {
            q.push(v[cur][i]);
        }
    }

    int cnt2 = v.size() - 1 - cnt;
    return abs(cnt2 - cnt);
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 1000;

    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> v(n + 1);
        for (int j = 0; j < wires.size(); j++)
        {
            if (i == j)
                continue;

            int start = wires[j][0];
            int end = wires[j][1];
            v[start].push_back(end);
            v[end].push_back(start);
        }

        answer = min(answer, gap(v));
        v.clear();
    }

    return answer;
}