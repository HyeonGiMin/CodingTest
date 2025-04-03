// 124 나라의 숫자
// https://school.programmers.co.kr/learn/courses/30/lessons/12899
// reference : https://non-stop.tistory.com/249
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";

    while (n > 0)
    {
        int b = n % 3;
        n /= 3;

        if (b == 0)
        {
            answer = "4" + answer;
            n -= 1;
        }
        else
        {
            answer = to_string(b) + answer;
        }
    }

    return answer;
}