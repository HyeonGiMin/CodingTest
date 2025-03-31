// 마법의 엘리베이터
// https://school.programmers.co.kr/learn/courses/30/lessons/148653
// reference : https://jinho082008.tistory.com/37
#include <string>
#include <vector>

using namespace std;

int solution(int storey)
{
    int answer = 0;

    while (storey > 0)
    {
        int lastDigit = storey % 10;        // 마지막 자리수
        int nextDigit = (storey / 10) % 10; // 마지막 자리수 앞

        if (lastDigit > 5 || (lastDigit == 5 && nextDigit >= 5))
        {
            // 올림 처리
            storey += (10 - lastDigit);
        }
        else
        {
            // 내림 처리
            storey -= lastDigit;
        }

        storey /= 10;

        // 클릭 횟수 추가
        answer += min(lastDigit, 10 - lastDigit);
    }

    return answer;
}