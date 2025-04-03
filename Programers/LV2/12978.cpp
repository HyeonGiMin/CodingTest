// 배달
// https://school.programmers.co.kr/learn/courses/30/lessons/12978
/// reference : https://school.programmers.co.kr/learn/courses/30/lessons/12978
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    // 그래프, (연결도니 마을 번호,거리);
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> distance(N + 1, INT_MAX); // 무한대로 초기화
    // 데이터타입, 내부 컨테이너, 비교 함수
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // 우선순위 큐 (거리, 노드 번호) - 거리가 짧은 순으로 정렬

    // 그래프 초기화: 도로 정보를 바탕으로 그래프(인접 리스트)를 구성
    for (const auto &r : road)
    {
        graph[r[0]].emplace_back(r[1], r[2]); // a->b 시간 c
        graph[r[1]].emplace_back(r[0], r[2]); // b->a 시간 c
    }

    // 다익스트라 알고리즘
    distance[1] = 0;  // 시작점 (1번 마을)의 거리는 0
    pq.emplace(0, 1); // 거리 0 노드 1

    while (!pq.empty())
    {
        int dist = pq.top().first; // 현재 노드 까지의 최단 거리
        int now = pq.top().second; // 현재 노드 번호
        pq.pop();

        // 이미 처리된 경우
        if (dist > distance[now])
            continue;

        // 현재 노트와 연결된 다른 노드들을 탐색
        for (const auto &next : graph[now])
        {
            int cost = dist + next.second;

            if (cost < distance[next.first])
            {
                distance[next.first] = cost;
                pq.emplace(cost, next.first);
            }
        }
    }

    answer = count_if(distance.begin(), distance.end(), [K](int d)
                      { return d <= K; });

    return answer;
}