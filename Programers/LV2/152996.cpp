// 시소 짝궁
// https://school.programmers.co.kr/learn/courses/30/lessons/152996
// reference : https://bonnate.tistory.com/502
#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights)
{
    // wieght, count
    map<long long, long long> m;

    // 초기 값 설정
    for (long long i : weights)
        ++m[i];

    long long answer = 0;

    for (auto p : m)
    {
        long long w = p.first;
        long long c = p.second;

        if (c > 1)
        {
            answer += (c * (c - 1) / 2); // 간선의 개수 계산식
        }

        // 나누어 떨어질 때만 계산
        if (w * 3 % 2 == 0)
        {
            if (m.find(w * 3 / 2) != m.end()) // 3:2 지정
                answer += (m[w * 3 / 2] * c);
        }
        if (w * 4 % 2 == 0)
        {
            if (m.find(w * 4 / 2) != m.end()) // 4:2 지점
                answer += (m[w * 4 / 2] * c);
        }

        if (w * 4 % 3 == 0)
        {
            if (m.find(w * 4 / 3) != m.end()) // 4:3 지점
                answer += (m[w * 4 / 3] * c);
        }
    }

    return answer;
}