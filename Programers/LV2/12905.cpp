// 가장 큰 정사각형 찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/12905
// reference : https://donggoolosori.github.io/2020/12/20/pgmsquare/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    // 1.대각선 값이 1인지 확인, 계속 증가
    for (int i = 1; i < board.size(); i++)
    {

        for (int j = 1; j < board[i].size(); j++)
        {
            if (board[i][j] == 1)
            {
                // 근처에 있는 가장 작은값 + 1 이 현재 값이 된다
                board[i][j] = 1 + min({board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]});
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}