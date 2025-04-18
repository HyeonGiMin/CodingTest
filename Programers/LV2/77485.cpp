// 행렬 테두리 회전하기
// https://school.programmers.co.kr/learn/courses/30/lessons/77485
#include <string>
#include <vector>
using namespace std;

int execute(vector<vector<int>> &circle, vector<int> query)
{
    int y1 = query[0] - 1;
    int x1 = query[1] - 1;
    int y2 = query[2] - 1;
    int x2 = query[3] - 1;
    int minimum = 10001;

    vector<pair<int, int>> v;

    // to left
    for (int i = x1 + 1; i <= x2; i++)
    {
        v.emplace_back(i, y1);
    }

    // to down
    for (int i = y1 + 1; i <= y2; i++)
    {
        v.emplace_back(x2, i);
    }

    // to right
    for (int i = x2 - 1; i >= x1; i--)
    {
        v.emplace_back(i, y2);
    }

    // to up
    for (int i = y2 - 1; i >= y1; i--)
    {
        v.emplace_back(x1, i);
    }

    // change
    int startValue = circle[y1][x1];

    // 시작 지점과 끝 지점이 중복
    for (int i = v.size() - 1; i >= 1; i--)
    {
        pair<int, int> cur = v[i];
        pair<int, int> prev = v[i - 1];

        circle[cur.second][cur.first] = circle[prev.second][prev.first];

        // 값 비교

        minimum = min(minimum, circle[cur.second][cur.first]);
    }

    circle[y1][x1 + 1] = startValue;
    minimum = min(minimum, startValue);

    return minimum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    vector<vector<int>> circle;

    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        vector<int> v;
        for (int j = 0; j < columns; j++)
        {
            v.emplace_back(value);
            value++;
        }
        circle.emplace_back(v);
    }

    for (auto q : queries)
    {
        int result = execute(circle, q);
        answer.emplace_back(result);
    }

    return answer;
}
