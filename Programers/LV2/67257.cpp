// 수식 최대화
// https://school.programmers.co.kr/learn/courses/30/lessons/67257
// reference : https://baebalja.tistory.com/188
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(long long a, long long b, char op)
{
    if (op == '-')
        return a - b;
    else if (op == '+')
        return a + b;
    else
        return a * b;
}

long long solution(string expression)
{
    long long answer = 0;
    vector<long long> nums;
    vector<char> opers;
    vector<char> op = {'+', '-', '*'};
    sort(op.begin(), op.end());

    string tmp = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            tmp += expression[i];
        }
        else
        {
            nums.emplace_back(stoll(tmp));
            opers.emplace_back(expression[i]);
            tmp = "";
        }
    }
    nums.emplace_back(stoll(tmp));

    do
    {
        vector<long long> nTmp(nums);
        vector<char> cTmp(opers);

        for (int i = 0; i < 3; i++)
        {
            // 우선순위가 일치하는 값 처리
            for (int j = 0; j < cTmp.size();)
            {
                if (op[i] == cTmp[j])
                {
                    long long result = calc(nTmp[j], nTmp[j + 1], cTmp[j]);
                    nTmp.erase(nTmp.begin() + j, nTmp.begin() + j + 2); // 숫자 제거
                    cTmp.erase(cTmp.begin() + j);
                    nTmp.insert(nTmp.begin() + j, result);
                }
                else
                    j++;
            }
        }

        answer = max(answer, abs(nTmp[0]));

    } while (next_permutation(op.begin(), op.end()));

    return answer;
}