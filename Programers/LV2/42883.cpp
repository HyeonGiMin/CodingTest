// 큰 수 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/42883
// reference: https://velog.io/@lamknh/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%81%B0-%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    // answer의 길이는 number.size()-k
    int len = number.size() - k;
    int start = 0;

    for (int i = 0; i < len; i++)
    {
        char c = number[start];
        int idx = start;
        for (int j = idx; j <= k + i; j++)
        {
            if (c < number[j])
            {
                c = number[j];
                idx = j;
            }
        }
        answer += c;
        start = idx + 1;
    }

    return answer;
}