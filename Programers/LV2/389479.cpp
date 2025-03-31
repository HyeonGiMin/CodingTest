// 서버 증설 횟수
// https://school.programmers.co.kr/learn/courses/30/lessons/389479
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k)
{
    int answer = 0;

    // Server Status
    //  Server의 Insert 시간을 넣어서 현재시간 - Insert 시간이 k 인 경우 Pop
    queue<int> serverQueue;

    for (int i = 0; i < players.size(); i++)
    {

        // 현재 서버 갯수 확인
        int curServerCount = serverQueue.size();
        int useCount = players[i];

        // 유저 숫자가 m명 미만이면 증설 필요 없음
        if (useCount >= m)
        {
            // 현재 서버 수와 비교해서 모자를 경우 증설
            useCount -= m; // 기본 1대 있음
            int totalServerCount = 0;
            while (useCount >= 0)
            {
                useCount -= m;
                totalServerCount++;
            }

            // 가용 서버 수가 부족할 경우 증설
            // 한 서버당 커버할 수 있는 숫자
            if (totalServerCount > curServerCount)
            {
                for (int j = 0; j < totalServerCount - curServerCount; j++)
                {
                    serverQueue.push(i);
                    answer++;
                }
            }
        }

        // 서버 반납
        curServerCount = serverQueue.size();
        for (int j = 0; j < curServerCount; j++)
        {
            int time = serverQueue.front();

            // i는 현재 시간, 클 경우 제거
            if (i - time + 1 >= k)
            {
                serverQueue.pop();
            }
            else
            {
                // 가장 앞에 있는 서버가 시간이 남을 경우 break;
                break;
            }
        }
    }

    return answer;
}