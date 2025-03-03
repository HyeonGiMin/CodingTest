//42578
//https://school.programmers.co.kr/learn/courses/30/lessons/42578
//reference https://velog.io/@dndud1024/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9D%98%EC%83%81-C
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> m;
    
    
    //종류 별로 저장
    for(auto clothe : clothes){
        m[clothe[1]]++;
    }
    
    //전체 경우의 수 에서 아예 안입은 경우만 빼면 된다
    for(auto p:m){
        answer*=(p.second+1);
    }
    
    return answer-1;
}
