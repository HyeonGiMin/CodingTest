// 우박수열 정적분
// https://school.programmers.co.kr/learn/courses/30/lessons/134239
// reference : https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9A%B0%EB%B0%95%EC%88%98%EC%97%B4-%EC%A0%95%EC%A0%81%EB%B6%84
#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    vector<pair<int, int>> m; // 좌표
    // 콜라츠 수행
    // y값이 5

    m.emplace_back(0, k);

    for (int i = 1; k != 1; i++)
    {
        // 1.입력된 수가 짝수라면
        if (k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k = (k * 3) + 1;
        }
        m.emplace_back(i, k);
    }
    for (auto c : ranges)
    {
        int s = c[0];
        int e = m.size() - 1 + c[1];
        double result = 0;
        for (int i = s; i < e; i++)
        {
            result += (double)(m[i].second + m[i + 1].second) / 2;
        }

        if (s > e)
            answer.emplace_back(-1.0);
        else
            answer.emplace_back(result);
    }

    return answer;
}