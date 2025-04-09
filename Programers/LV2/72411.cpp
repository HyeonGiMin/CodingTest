// 메뉴 리뉴얼
// https://school.programmers.co.kr/learn/courses/30/lessons/72411
// reference : https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%A9%94%EB%89%B4-%EB%A6%AC%EB%89%B4%EC%96%BC
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;

void dfs(int idx, string tmp, string order)
{
    if (tmp.size() > order.size())
        return;

    // 메뉴 추가
    m[tmp]++;

    for (int i = idx; i < order.size(); i++)
    {
        dfs(i + 1, tmp + order[i], order);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    for (auto order : orders)
    {
        sort(order.begin(), order.end()); // 정렬
        dfs(0, "", order);                // 조합할 수 잇는 모든 메뉴를 넣는다.
    }

    for (auto menuSize : course)
    {
        int mostOrdered = 0;

        for (auto menu : m)
        {
            if (menu.first.size() == menuSize)
            {
                // 코스의 사이즈를 만족하면서 가장 많이 선택된 횟수 갱신
                mostOrdered = max(mostOrdered, menu.second);
            }
        }

        if (mostOrdered <= 1)
            continue; // 최소 2 이상이야 한다.

        for (auto menu : m)
        {
            if (menu.first.size() == menuSize && menu.second == mostOrdered)
            {
                answer.push_back(menu.first); // 조건에 부합하면 넣어준다.
            }
        }
    }

    sort(answer.begin(), answer.end()); // 사전순으로 정렬

    return answer;
}