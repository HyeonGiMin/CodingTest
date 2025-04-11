// 줄 서는 방법
// https://school.programmers.co.kr/learn/courses/30/lessons/12936
//  reference : https://kangworld.tistory.com/258
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long facto(int n)
{
    if (n == 1)
        return 1;

    return n * facto(n - 1);
}

vector<int> solution(int n, long long k)
{
    vector<int> answer;

    vector<int> v;
    long long idx;
    long long boundary;

    // Vector에 번호 추가
    for (int i = 1; i <= n; i++)
    {
        v.emplace_back(i);
    }

    k--;

    // 첫 번째 원소가 동일한 집합의 수는 (n-1)!
    while (k != 0)
    {
        boundary = facto(--n);
        idx = k / boundary;
        k %= boundary;

        answer.emplace_back(v.at(idx));
        v.erase(v.begin() + idx);
    }

    for (int i = 0; i < v.size(); i++)
    {
        answer.emplace_back(v[i]);
    }

    return answer;
}