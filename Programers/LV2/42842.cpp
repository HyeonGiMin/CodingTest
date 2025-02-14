//카펫
//https://school.programmers.co.kr/learn/courses/30/lessons/42842
//reference https://jypgamepro.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%ED%8E%ABC
//reference https://hub1234.tistory.com/35
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int capet = brown+yellow;
    
    for(int i=capet/2;i>0;i--){
        if(capet%i==0){
            int w=i;
            int h=capet/i;
            
            if((w-2)*(h-2) == yellow){
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    
    
    return answer;
}
