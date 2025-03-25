// 삼각 달팽이
// https://school.programmers.co.kr/learn/courses/30/lessons/68645
//  reference : https://yabmoons.tistory.com/575
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> m(n + 1, vector<int>(n + 1));

    int maxNum = (n * (n + 1)) / 2;

    int top = 1;    // 상단
    int bottom = n; // 바닥
    int left = 1;   // 왼쪽
    int right = 0;  // 오른쪽에 넣은 횟수

    int num = 1;
    // 0 -> 1 - > 2
    int state = 0; // 0:위->아래, 1:왼->오 2: 아래 -> 위(대각);

    while (num <= maxNum)
    {
        if (state == 0)
        {
            // 위에서 아래로
            for (int i = top; i <= bottom; i++)
            {
                m[i][left] = num++;
            }
            top++;
            left++;
            state = 1;
        }
        else if (state == 1)
        {
            for (int i = left; i <= bottom - right; i++)
            {
                m[bottom][i] = num++;
            }
            bottom--;
            state = 2;
        }
        else if (state == 2)
        {
            for (int i = bottom; i >= top; i--)
            {
                m[i][i - right] = num++;
            }
            right++;
            top++;
            state = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            answer.push_back(m[i][j]);
        }
    }

    return answer;
}