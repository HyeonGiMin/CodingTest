//[PCCP 기출문제] 2번 / 퍼즐 게임 챌린지
// https://school.programmers.co.kr/learn/courses/30/lessons/340212
// reference : https://velog.io/@dndud1024/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-PCCP-%EA%B8%B0%EC%B6%9C%EB%AC%B8%EC%A0%9C-2%EB%B2%88-%ED%8D%BC%EC%A6%90-%EA%B2%8C%EC%9E%84-%EC%B1%8C%EB%A6%B0%EC%A7%80-C
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit)
{
    long long answer = 0;

    long long level_right = 100000;
    long long level_left = 1;

    while (level_left <= level_right)
    {

        long long level_mid = (level_right + level_left) / 2; // 중간 값
        long long cur_times = 0;

        for (int i = 0; i < diffs.size(); i++)
        {
            if (diffs[i] <= level_mid)
            {
                cur_times += times[i];
            }
            else
            {
                cur_times += (diffs[i] - level_mid) * (times[i] + times[i - 1]) + times[i];
            }
        }

        if (cur_times <= limit)
        {
            level_right = level_mid - 1;
            answer = level_mid;
        }
        else
        {
            level_left = level_mid + 1;
        }
    }
    return answer;
}