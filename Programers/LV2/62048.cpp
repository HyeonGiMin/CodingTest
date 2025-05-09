// 멀쩡한 사각형
// https://school.programmers.co.kr/learn/courses/30/lessons/62048
//  reference : https://codingwell.tistory.com/30
#include <numeric>
using namespace std;

long long solution(int w, int h)
{
    long long answer = 1;
    long long llw = (long long)w;
    long long llh = (long long)h;
    // 잘려나가는 격자의 수는 w+h-1;
    // 최대공약수 수 만큼 곱해야한다

    // 최대공약수 구하기
    int nGcd = gcd(w, h);

    long long total = llw * llh;
    answer = total - (llw + llh);
    answer += nGcd;

    return answer;
}