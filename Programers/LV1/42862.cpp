//체육복
//https://school.programmers.co.kr/learn/courses/30/lessons/42862
//insight https://mungto.tistory.com/41


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //모두에게 체육복이 있다.
    vector<int> students(n,1);
    
    //체육복이 없는 경우 -1, 여벌이 있는 경우 +1
    for(int l:lost){
        students[l-1]--;
    }
    
    for(int r:reserve){
        students[r-1]++;
    }
    
    for(int i=0;i<students.size();i++){
        
        //체육복이 0개라면
        if(students[i] ==0){
            //앞에 친구의 값이 있는지 확인
            if(i!=0 && students[i-1] == 2){
                students[i]++;
                students[i-1]--;
            }else if(i !=students.size()-1 && students[i+1]==2){ //뒤에 친구의 값이 있는지 확인 
                students[i]++;
                students[i+1]--;
            }
        }
    }
    
    for (auto s : students)
        if (s != 0)  answer++;
    
    return answer;
}