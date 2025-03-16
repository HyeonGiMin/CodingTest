//주식가격
//https://school.programmers.co.kr/learn/courses/30/lessons/42584
//reference: https://non-stop.tistory.com/410
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    
    for(int i=0;i<prices.size()-1;i++){
        while(!s.empty() && prices[i]<prices[s.top()]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        answer[s.top()] = (prices.size()-1)-s.top();
        s.pop();
    }
    answer[prices.size()-1]=0;
    
    return answer;
}