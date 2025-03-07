//기능개발
//https://school.programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0; i < speeds.size(); ++i)
        q.push(i);


    
     while(!q.empty()){
        int today=0;
        
        for(int i=0;i<speeds.size();i++){
            progresses[i]+=speeds[i];
        }
        
         while(!q.empty() && progresses[q.front()] >= 100){ // 100이 넘어갔을 때 처리
            ++today;
            q.pop();
        }
        
        if(today!=0)
            answer.push_back(today);

    }
    
    
    return answer;
}