// 이모티콘 할인행사
// https://school.programmers.co.kr/learn/courses/30/lessons/150368
// reference : https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9D%B4%EB%AA%A8%ED%8B%B0%EC%BD%98-%ED%95%A0%EC%9D%B8%ED%96%89%EC%82%AC
#include <string>
#include <vector>

using namespace std;

int dis[4] = {40, 30, 20, 10};
vector<pair<int, int>> price(7, {0, 0}); // 할인된 가격, 할인률
vector<int> answer(2, 0);

void dfs(int cnt, int n, vector<vector<int>> users, vector<int> emoticons)
{
    if (n == cnt) // 이모티콘에 대한 할인율을 다 기입했을때
    {
        int plus = 0, sum = 0;

        // 사용자 순회
        for (int i = 0; i < users.size(); i++)
        {
            int tmp = 0;
            // 가격을 순회하면서 원하는 할인률 이상이면 구매
            for (int j = 0; j < n; j++)
            {
                if (users[i][0] <= price[j].second)
                    tmp += price[j].first;
            }

            if (tmp >= users[i][1])
                plus++;
            else
                sum += tmp;
        }

        if (plus > answer[0])
        {
            answer[0] = plus;
            answer[1] = sum;
        }
        else if (plus == answer[0] && sum >= answer[1])
        {
            answer[1] = sum;
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        price[cnt].first = (100 - dis[i]) * emoticons[cnt] / 100; // 할인된 가격
        price[cnt].second = dis[i];
        dfs(cnt + 1, n, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{

    dfs(0, emoticons.size(), users, emoticons);

    return answer;
}