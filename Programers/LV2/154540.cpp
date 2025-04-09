// 무인도 여행
// https://school.programmers.co.kr/learn/courses/30/lessons/154540
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(vector<vector<bool>> &visit, vector<string> maps, int x, int y)
{
    queue<pair<int, int>> q;
    // 현재 위치에서 탐색을 시작
    q.emplace(x, y);

    visit[y][x] = true;

    int sum = 0;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        sum += (maps[cy][cx] - '0');
        q.pop();

        // 탐색
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;

            // 범위 확인
            if (nx < 0 || ny < 0 || nx >= maps[y].size() || ny >= maps.size() || visit[ny][nx])
                continue;

            // 값 확인
            if (maps[ny][nx] != 'X')
            {
                q.push({nx, ny});
                visit[ny][nx] = true;
            }
        }
    }

    return sum;
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;

    // 벙문여부 초기화
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));

    // 01.맵 탐색 시작
    for (int y = 0; y < maps.size(); y++)
    {
        for (int x = 0; x < maps[y].size(); x++)
        {
            char point = maps[y][x];

            if (point == 'X')
                continue;

            // 방문하지 않은 경우 탑색 시작
            if (visit[y][x] == false)
            {
                int result = dfs(visit, maps, x, y);
                if (result > 0)
                {
                    answer.emplace_back(result);
                }
            }
        }
    }

    // 값이 없을경우 -1 추가
    if (answer.empty())
        answer.emplace_back(-1);

    sort(answer.begin(), answer.end());

    return answer;
}
