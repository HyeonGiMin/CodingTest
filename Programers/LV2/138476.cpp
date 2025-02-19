//귤 고르기
//https://school.programmers.co.kr/learn/courses/30/lessons/138476
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m;
    
    for(int t:tangerine){
        m[t]++;
    }
    
    vector<int> v;
    for(auto p:m){
        v.push_back(p.second);
    }
    
    //오름차순으로 정렬
    sort(v.begin(),v.end(),greater<int>());
    
    int count=0;
    for(int i=0;i<v.size();i++){
        if(count>=k) break;
        answer++;
        count+=v[i];
    }
    
    return answer;
}