// 좌제 진행하기
// https://school.programmers.co.kr/learn/courses/30/lessons/176962#
// reference : https://tnsn.tistory.com/10
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Task
{
public:
    string job;
    int startTime;
    int workingTime;
    int remainTime;
};

int convertToMinute(string time)
{
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);

    return stoi(hour) * 60 + stoi(min);
}

bool comp(Task a, Task b)
{
    return a.startTime < b.startTime;
}

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    vector<Task> tasks;
    stack<Task> waitStack;

    // 클래스로 변환
    for (auto plan : plans)
    {
        Task t;
        t.job = plan[0];
        t.startTime = convertToMinute(plan[1]);
        t.workingTime = stoi(plan[2]);
        t.remainTime = 0;

        tasks.emplace_back(t);
    }

    // 1.시간순으로 정렬
    sort(tasks.begin(), tasks.end(), comp);

    int taskSize = tasks.size();

    for (int i = 0; i < taskSize - 1; i++)
    {
        Task curTask = tasks[i];
        Task nextTask = tasks[i + 1];

        int remainTime = nextTask.startTime - (curTask.startTime + curTask.workingTime);

        // 현재 잡이 끝나지 않을 경우
        if (remainTime < 0)
        {
            curTask.remainTime = -remainTime;
            waitStack.push(curTask);
        }
        else
        {
            answer.emplace_back(curTask.job);
            while (remainTime && !waitStack.empty())
            {
                Task &t = waitStack.top();

                if (t.remainTime > remainTime)
                {
                    t.remainTime -= remainTime;
                    remainTime = 0;
                }
                else
                {
                    answer.emplace_back(t.job);
                    remainTime -= t.remainTime;
                    waitStack.pop();
                }
            }
        }
    }

    // 마지막 일 추가
    answer.emplace_back(tasks[taskSize - 1].job);

    while (!waitStack.empty())
    {
        Task t = waitStack.top();
        answer.emplace_back(t.job);
        waitStack.pop();
    }

    return answer;
}