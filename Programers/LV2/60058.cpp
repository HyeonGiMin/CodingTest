// 괄호 변환
// https://school.programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool isBalancedBracket(string s)
{
    if (s == "")
        return false;

    int left = count(s.begin(), s.end(), '(');
    int right = count(s.begin(), s.end(), ')');

    if (left != right)
        return false;
    else
        return true;
}

bool isCorrectBracket(string s)
{
    stack<char> stk;

    // 올바른 괄호인지 확인
    for (int i = 0; i < s.length(); i++)
    {

        if (stk.empty())
        {
            stk.push(s[i]);
        }
        else
        {
            // stack의 값이 있을경우 마지막 값 확인
            char last = stk.top();

            // 짝이 맞는 경우 Stack에서 제거
            if (last == '(' && s[i] == ')')
            {
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
    }

    if (stk.empty())
        return true;

    return false;
}

string divied(string s)
{

    // 01.입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if (s == "")
        return "";

    // 02.문자열 분리
    int idx = 0; // 분리 지점
    for (int i = 0; i < s.length(); i++)
    {
        if (isBalancedBracket(s.substr(0, i + 1)))
        {
            idx = i + 1;
            break;
        }
    }

    string u = s.substr(0, idx);
    string v = s.substr(idx);

    string result = "";
    if (isCorrectBracket(u))
    {
        // 03. u가 올바른 괄호 문자열인 경우
        result = u + divied(v);
    }
    else
    {
        // 04. u가 올바른 괄호 문자열이 아닌 경우
        result = "(" + divied(v) + ")";

        // u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        string temp = u.substr(1, u.length() - 2);
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == '(')
                result += ')';
            else
                result += '(';
        }
    }

    return result;
}

string solution(string p)
{
    string answer = "";

    answer = divied(p);
    return answer;
}