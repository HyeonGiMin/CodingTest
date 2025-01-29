#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int,double> &a,pair<int,double> &b){
    if(a.second==b.second)
        return a.first < b.first;
    else 
        //실패율이 높은 스테이지 부터
        return a.second>b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> failPercent; // <스테이지, 실패율> 
    int userCount =stages.size();
    
    for(int i=1;i<=N;i++){
    
        //현재 스테이지의 유저의 수 확인 
        int noClearUser = count(stages.begin(),stages.end(),i);
        
        if(noClearUser == 0){
            failPercent.push_back(make_pair(i,0));
        }else{
            //실패율 계산 
            double fp = (double)noClearUser/userCount;
            //실패율 추가 
            failPercent.push_back(make_pair(i,fp));
            
            //실패한 유저의 수 만큼 제외
            userCount-=noClearUser;
        }
    }
    
    //정렬
    sort(failPercent.begin(),failPercent.end(),cmp);
    
    //별도의 vector로 추출 
    for(auto p:failPercent){
        answer.push_back(p.first);
    }
    
    
    return answer;
}