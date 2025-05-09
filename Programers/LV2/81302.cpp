// 거리두기 확인하기
// https://school.programmers.co.kr/learn/courses/30/lessons/81302
// reference : https://sianblack320.tistory.com/230
#include <string>
#include <vector>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
using namespace std;

bool dfs(vector<string> &place, vector<vector<bool>> &visit, int y, int x, int count)
{
    if (count >= 3)
        return true;
    if (count > 0 && place[y][x] == 'P')
        return false; // 바로 근처에 사람이 있는 경우

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
            continue;

        if (visit[ny][nx])
            continue;

        if (place[ny][nx] == 'X')
            continue;

        visit[ny][nx] = 1;
        if (!dfs(place, visit, ny, nx, count + 1))
            return false;
        visit[ny][nx] = 0;
    }

    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    // 기본적으로 1로 초기화
    vector<int> answer(places.size(), 1);

    // 맨허튼 거리가 (p1,p2) 와(q1,q2)면 맨허튼 거리 = ∣p1−q1∣+∣p2−q2∣
    // 맨하튼 거리가 2이하인 경우엔 안된다.

    for (int idx = 0; idx < places.size(); idx++)
    {
        vector<string> place = places[idx];
        // 멘하튼 거리가 2 이하인 경우 -1로 하고 break;
        // 파티션이 사이에 있는경우는 OK
        vector<vector<bool>> visit(5, vector<bool>(5, false));

        // 사람기준으로 호출, 빈테이블이면 한번 더 호출

        // 5x5로 고정
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (place[i][j] == 'P')
                {
                    visit[i][j] = true;
                    if (!dfs(place, visit, i, j, 0))
                    {
                        answer[idx] = 0;
                        break;
                    }
                }
            }
        }
    }

    return answer;
}
