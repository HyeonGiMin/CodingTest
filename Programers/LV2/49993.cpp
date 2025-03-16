//스킬트리
//https://school.programmers.co.kr/learn/courses/30/lessons/49993
//reference: https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%8A%A4%ED%82%AC%ED%8A%B8%EB%A6%AC
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> m;
    
    //skill의 각 스킬이 몇번째 순서인지 넣기
    for(int i=0;i<skill.size();i++){
        m[skill[i]]=i;
    }
     
    //skill의 각 idx가 순차적 이어야 한다.
    for(string skill_tree:skill_trees){
        int idx=0;
        bool complete =true;
        
        for(auto s:skill_tree){
             // 스킬트리에 있는지 확인
            if(m.find(s) == m.end()){
                continue;
            } else{
                if(m[s] != idx){
                    complete=false;
                    break;
                }
                idx++;
            }
            
           
        }
        
        if(complete)
            answer++;
        
    }
    
    
    
    return answer;
}