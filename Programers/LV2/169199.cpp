// 리코쳇 로봇
// https://school.programmers.co.kr/learn/courses/30/lessons/169199
#include <string>
#include <vector>
#include <queue>
#define INF 100000

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(vector<string> board)
{
    int answer = -1;

    // 횟수
    vector<vector<int>> v(board.size(), vector<int>(board[0].size(), 100000));
    queue<pair<int, int>> q;

    // 시작 지점 확인
    int sX = -1, sY = -1;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                sX = j;
                sY = i;
                break;
            }
        }
    }

    q.emplace(sX, sY);
    v[sY][sX] = 0;

    while (!q.empty())
    {
        int cX = q.front().first;
        int cY = q.front().second;
        q.pop();

        // 현재 위치가 G인경우 Break;
        if (board[cY][cX] == 'G')
        {
            if (answer == -1)
            {
                answer = v[cY][cX];
            }
            else
            {
                answer = min(answer, v[cY][cX]);
            }
            break;
        }

        // 현재 위치 기반으로 상하좌우 값 확인
        for (int i = 0; i < 4; i++)
        {
            int nX = cX + dx[i];
            int nY = cY + dy[i];

            // 벽이거나 D이면 그 방향으로는 이동X
            if (nX < 0 || nY < 0 || nX >= board[0].size() || nY >= board.size())
                continue;

            if (board[nY][nX] == 'D')
                continue;

            // D 또는 벽을 만날때 까지 해당 방향으로 이동
            while (true)
            {
                int tX = nX + dx[i];
                int tY = nY + dy[i];

                if (tX < 0 || tY < 0 || tX >= board[0].size() || tY >= board.size() || board[tY][tX] == 'D')
                    break;

                // 다음으로 이동
                nX = tX;
                nY = tY;
            }

            // 지나온 적이 있는 경우 큐에 추가 X
            if (v[nY][nX] != INF)
                continue;

            q.emplace(nX, nY);

            // 이동 값 증가
            v[nY][nX] = min(v[cY][cX] + 1, v[nY][nX]);
        }
    }

    return answer;
}