//구명보트
//https://school.programmers.co.kr/learn/courses/30/lessons/42885
//reference https://hwan-shell.tistory.com/200
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int min=0;
    //한 구명보트에 사람을 많이 채워야 한다.
    //작은 순으로 정렬
    sort(people.begin(),people.end());
    

    while(people.size()>min){
        int max = people.back(); // 큰사람부터 태운다.
        people.pop_back();
        if(people[min]+max<=limit){
            min++; //제일 작은 사람을 같이 태운다.
        }
        answer++; // 구명보트 사용
          
    }
    
    
    return answer;
}