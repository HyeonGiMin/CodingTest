//예상 대진표 
//https://school.programmers.co.kr/learn/courses/30/lessons/12985
//reference https://velog.io/@krydyh/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-C-%EC%98%88%EC%83%81-%EB%8C%80%EC%A7%84%ED%91%9C
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    //A와 B가 만날때 까지
    while(a != b) {
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
        answer++;
    }
    return answer;
}

// 1번 vs 2번 -> 1번

// 3번 vs 4번 -> 2번

// 5번 vs 6번 -> 3번

// 7번 vs 8번 -> 4번