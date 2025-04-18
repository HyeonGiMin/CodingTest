// 디펜스 게임
// https://school.programmers.co.kr/learn/courses/30/lessons/142085
//  reference : https://flrjtwjrjt.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%94%94%ED%8E%9C%EC%8A%A4-%EA%B2%8C%EC%9E%84-Lv2-C
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int round = 0;

    priority_queue<int> q; // 우선순위 큐 사용

    for (; round < enemy.size(); round++)
    {
        q.push(enemy[round]); // 현재 적
        n -= enemy[round];

        // 무적권 사용
        while (!q.empty() && n < 0 && k > 0)
        {
            n += q.top();
            k--;
            q.pop();
        }

        if (n < 0)
        {
            break;
        }
    }

    return round;
}