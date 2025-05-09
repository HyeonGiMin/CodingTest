// 하노이의 탑
// https://school.programmers.co.kr/learn/courses/30/lessons/12946
// reference : https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%95%98%EB%85%B8%EC%9D%B4%EC%9D%98-%ED%83%91
#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int go, int to, vector<vector<int>> &ans)
{
    if (n == 1)
    {
        ans.push_back({go, to});
        return;
    }
    hanoi(n - 1, go, 6 - go - to, ans); // n-1 개의 원판을 시작점, 목표점을 제외한 곳으로 이동
    hanoi(1, go, to, ans);              // n번째 원판을 목표지점으로 이동
    hanoi(n - 1, 6 - go - to, to, ans); // n-1 개의 원판을 목표점으로 이동
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

    // 기둥 1,2,3

    hanoi(n, 1, 3, answer);

    return answer;
}