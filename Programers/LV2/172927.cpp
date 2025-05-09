// 광물 캐기
// https://school.programmers.co.kr/learn/courses/30/lessons/172927
// reference : https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B4%91%EB%AC%BC-%EC%BA%90%EA%B8%B0
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = INT32_MAX;

int count_tired(int cnt, int idx, vector<int> mine)
{
    int pick = (int)pow(5, 2 - idx), res = 0;

    for (int i = cnt * 5; i < (cnt + 1) * 5 && i < mine.size(); i++)
    {
        int num = mine[i] / pick;
        if (num == 0)
            res++;
        else
            res += num;
    }

    return res;
}

void dfs(int cnt, int res, vector<int> picks, vector<int> mine)
{
    // 곡괭이를 다 썻거나, 광물을 다 캤으면
    if ((!picks[0] && !picks[1] && !picks[2]) || cnt * 5 >= mine.size())
    {
        answer = min(answer, res); // 최소값 저장
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (picks[i])
        {
            picks[i]--;
            dfs(cnt + 1, res + count_tired(cnt, i, mine), picks, mine);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    vector<int> mine;
    for (auto m : minerals)
    {
        if (m[0] == 'd')
            mine.push_back(25);
        else if (m[0] == 'i')
            mine.push_back(5);
        else
            mine.push_back(1);
    }

    dfs(0, 0, picks, mine);
    return answer;
}