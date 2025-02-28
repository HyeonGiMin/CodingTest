//신고 결과 받기
//https://school.programmers.co.kr/learn/courses/30/lessons/92334
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct INFO
{
    int reportedCnt;
    //한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리를 위해 Set 사용
    set<string> requestId;
    int rspEmailCnt;
    
    INFO(){
        reportedCnt=0;
        rspEmailCnt=0;
    }
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> blockedId;
    map<string,INFO*> m;
    
    //각 유저별 신고 당한 횟수와 유저가 신고한 id를 map으로 만든다.
    for(string id : id_list){
        INFO* info = new INFO;
        m.insert(make_pair(id,info));
    }
    
    //신고 내용들을 확인 한다.
    for(string r:report){
        string reporter = r.substr(0,r.find(" "));
        string reported = r.substr(r.find(" ")+1);
        
        //이전에 신고한 이력이 없으면 카운트 증가
        if(m[reporter]->requestId.find(reported) == m[reporter]->requestId.end()){  
            //신고당한 유저 카운트 증가
            m[reported]->reportedCnt++;
        }
        
        //신고한 유저에 유저가 신고한 아이디 추가
        m[reporter]->requestId.insert(reported);
     
    }
    
    //block된 id를 확인
    for(auto it = m.begin();it!=m.end();it++){
        if(it->second->reportedCnt>=k){
            blockedId.push_back(it->first);
        }
    }
    
    //이메일을 몇번 받을지 확인
    for(auto it = m.begin();it!=m.end();it++){
        for(string id:blockedId){
            //요청한 대상에 blocked id 가 있는 경우 response count 증가
           if(it->second->requestId.find(id) != it->second->requestId.end()){
                it->second->rspEmailCnt++;
           }
        }
        
    }
    

    //순서를 위해 id_list 순서 기반으로 값을 찾아서 answer에 추가 
    for(string id:id_list){
        answer.push_back(m[id]->rspEmailCnt);
    }
    
    
    return answer;
}