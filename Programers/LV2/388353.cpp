// 지게차와 크레인
// https://school.programmers.co.kr/learn/courses/30/lessons/388353
// reference : https://59travel.tistory.com/114
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void gCar(char request, vector<string> &storage, int n, int m)
{
    // 테두리를 순회하면서, 0을 만나면 안으로 들어가서 검사
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<pair<int, int>> delPoint;

    // 순회

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // 바깥쪽만 확인
            if (i != 0 && i != n - 1 && j != 0 && j != m - 1)
                continue;

            if (storage[i][j] == request)
                delPoint.emplace_back(i, j);
            else if (storage[i][j] == '0')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();

                    int x = p.first;
                    int y = p.second;

                    // 네 방향 확인
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;

                        if (storage[nx][ny] == request && !visited[nx][ny])
                        {
                            delPoint.emplace_back(nx, ny);
                            visited[nx][ny] = true;
                        }

                        if (storage[nx][ny] == '0' && !visited[nx][ny])
                        {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    for (auto p : delPoint)
    {
        storage[p.first][p.second] = '0';
    }
}

void crain(char request, vector<string> &storage, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (storage[i][j] == request)
                storage[i][j] = '0';
        }
    }
}

int solution(vector<string> storage, vector<string> requests)
{
    int answer = 0;
    int n = storage.size();    // 세로줄
    int m = storage[0].size(); // 가로줄

    // 제거할 경우 해당 값을 0으로 변경

    for (auto request : requests)
    {
        // size가 1인지 2인지 확인
        if (request.size() == 1)
            gCar(request[0], storage, n, m);
        else
            crain(request[0], storage, n, m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (storage[i][j] != '0')
                answer++;
        }
    }

    return answer;
}