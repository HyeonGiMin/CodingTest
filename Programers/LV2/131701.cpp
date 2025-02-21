//연속 부분 수열 합의 개수
//https://school.programmers.co.kr/learn/courses/30/lessons/131701
//reference https://hello-world-cpp.tistory.com/165
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    //중복을 허용하지 않음
    set<int> s;
    
    for(int i=0;i<elements.size();i++){
        int sum=0;
        //순회 하면서 부분 수열의 합을 구한다.
        for(int j=i;j<elements.size()+i;j++){
            int idx = j%elements.size();
            sum+=elements[idx];
            s.emplace(sum);
        }
    }
    
     answer = s.size();
    
    return answer;
}