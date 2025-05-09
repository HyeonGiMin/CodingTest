// 점 찍기
// https://school.programmers.co.kr/learn/courses/30/lessons/140107
// reference : https://non-stop.tistory.com/624
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;

    // x=y 인 점의 갯수 + x축 기준값 *2

    // k만큼씩 늘어남
    // x,y는 k의 배수
    for (int i = 0; i <= d; i += k)
    {
        // a^2+b^2 = c^2
        int y = sqrt((long long)d * d - (long long)i * i);

        // i는 x 값일때 해당 거리의 최대 Y좌표의 갯수만큼 점이 찍힌다
        answer += ((y / k) + 1);
    }

    return answer;
}