// 미로 탈출
// https://school.programmers.co.kr/learn/courses/30/lessons/159993
//  reference : https://beankong-devlog.tistory.com/101
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool isOpend = false;

int solution(vector<string> maps)
{
    int answer = -1;

    // 방문여부 표시를 위한 이차원 배열 생성
    // 0으로 초기화
    vector<vector<int>> visit(maps.size(), vector<int>(maps[0].size(), 0));
    queue<pair<int, int>> q;

    int pos_x = -1, pos_y = -1;

    // 시작점 찾기

    for (int y = 0; y < maps.size(); y++)
    {
        for (int x = 0; x < maps[0].size(); x++)
        {
            if (maps[y][x] == 'S')
            {
                pos_x = x;
                pos_y = y;
                break;
            }
        }

        if (pos_x != -1)
            break;
    }

    // queue에 시작점 추가
    q.push({pos_x, pos_y});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        // 레버가 올라간 상태에서 출구를 만났을떄
        if (isOpend && maps[y][x] == 'E')
        {
            answer = visit[y][x];
            break;
        }
        else if (!isOpend && maps[y][x] == 'L') // 레버가 안올라간 상태에서 레버를 만났을때
        {
            isOpend = true;
            int time = visit[y][x];

            // queue 초기화
            q = queue<pair<int, int>>();
            fill(visit.begin(), visit.end(), vector(visit[0].size(), 0));

            // 레버까지 걸린 시간
            visit[y][x] = time;
        }

        // 다음 방문지 찾기
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < maps[0].size() && ny < maps.size())
            {
                if (maps[ny][nx] != 'X' && visit[ny][nx] == 0)
                {
                    q.push({nx, ny});
                    visit[ny][nx] = visit[y][x] + 1; // 이전값에 1ㅊ 추가
                }
            }
        }
    }

    return answer;
}