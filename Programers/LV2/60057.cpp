// 문자열 압축
// https://school.programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>
#include <queue>

using namespace std;

string createString(string s, int dup)
{
    string result = "";
    if (dup >= 1)
    {
        s = to_string(dup + 1) + s;
    }
    result += s;
    return result;
}

int compress(string s, int len)
{
    queue<string> q;
    string result = "";

    // 문자열을 잘라셔 queue에 넣는다.
    for (int i = 0; i < s.size(); i += len)
    {
        q.push(s.substr(i, len));
    }

    // 일치할 경우 count추가 후 front 값 제거
    // 일치하지 않을 경우 문자열에 추가
    int dup = 0;
    string prev = q.front();
    q.pop();
    while (!q.empty())
    {
        // 큐를 꺼내면서 front에 있는 값과 일치하는지 확인
        string next = q.front();
        q.pop();

        if (prev == next)
        {
            dup++;
        }
        else
        {
            // dup 값이 1이상일 경우 앞에 숫자를 붙임
            result += createString(prev, dup);

            prev = next;
            // 초기화
            dup = 0;
        }
    }

    if (!prev.empty())
    {
        result += createString(prev, dup);
    }

    return result.length();
}

int solution(string s)
{
    int answer = s.length();

    // 문자열을 N개씩 자르면서 압축 수행해서 비교
    // 최대는 문자열의 길이 /2
    for (int i = 1; i <= s.length() / 2; i++)
    {

        int size = compress(s, i);
        answer = min(answer, size);
    }

    return answer;
}