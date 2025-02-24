//n^2 배열 자르기
//https://school.programmers.co.kr/learn/courses/30/lessons/87390
//reference https://velog.io/@krydyh/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-C-n2-%EB%B0%B0%EC%97%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    //left 부터 right 까지 잘라서 표시
    //행은 나눈 몫, 열은 나머지
    for(long long i=left;i<=right;i++){
        long long x = i/n;
        long long y = i%n;
        
        //어떤 값이 들어갈지 비교
        answer.push_back(max(x, y) + 1);
    }
    
    return answer;
}