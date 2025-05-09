// N-Queen
// https://school.programmers.co.kr/learn/courses/30/lessons/12952
// reference : https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-N-Queen
#include <string>
#include <vector>

using namespace std;

bool isAble(int idx, int cnt, vector<int> &board)
{
    for (int i = 0; i < cnt; i++)
    {
        if (board[i] == idx)
            return false; // 같은 수평선에 있는 경우
        if (abs(board[i] - idx) == abs(cnt - i))
            return false; // 대각선에 있는경우
    }
    return true;
}

void dfs(int cnt, int n, vector<int> &board, int &answer)
{
    if (cnt == n)
    {
        answer++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isAble(i, cnt, board))
        {
            board[cnt] = i;
            dfs(cnt + 1, n, board, answer);
        }
    }
}

int solution(int n)
{
    int answer = 0;
    vector<int> board(n, 0);
    dfs(0, n, board, answer);

    return answer;
}
