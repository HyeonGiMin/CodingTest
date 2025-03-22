//두 큐 합 같게 만들기
//https://school.programmers.co.kr/learn/courses/30/lessons/118667
//reference: https://wadekang.tistory.com/58
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int S;

int addIndex(int idx){
    return idx+1 >= 2*S?0:idx+1; 
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    S= queue1.size();
    
    //queue1의 뒤에 queue2를 붙인다
    queue1.insert(queue1.end(),queue2.begin(),queue2.end());
    int q1_f =0;
    int q1_e =S-1;
    int q2_f =S;
    int q2_e = 2*S-1;
    
    while(answer<=4*S){
        if(sum1>sum2){
            //q1 -> q2
            sum1-=queue1[q1_f];
            sum2+=queue1[q1_f];
            
            q1_f = addIndex(q1_f);
            q2_e = addIndex(q2_e);
            
        }else if(sum1<sum2){
            //q1 <- q2
            sum1+=queue1[q2_f];
            sum2-=queue1[q2_f];
            
            q2_f = addIndex(q2_f);
            q1_e = addIndex(q1_e);
        }else
            return answer;
        
        answer++;
    }
    
    return -1;
}