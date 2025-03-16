//택배상자
//https://school.programmers.co.kr/learn/courses/30/lessons/131704
//reference: https://bendeng-life.tistory.com/149
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int idx=0;
    //컨베이어벨트에서는 1->n까지 들어가있다.
    stack<int> stk;
    
    for(int i=0;i<order.size();i++){
        stk.push(i+1);
        
        //order[idx]의 값을 꺼낸다.
        while(!stk.empty() && stk.top() ==order[idx]){
            stk.pop();
            answer++;
            idx++;
        }
    }
    
    
    return answer;
}