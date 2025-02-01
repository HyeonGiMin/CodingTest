//숫자 짝꿍
//https://school.programmers.co.kr/learn/courses/30/lessons/131128

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> vec;
    map<char,int> map;
    //x를 파싱해서 map으로 만든다
    for(char c:X){
        //값이 Map에 없는 경우 1로 insert
        if(map.find(c)==map.end()){
            map.insert(make_pair(c,1));
        }else{
            map[c]+=1; //1증가
        }
    }
    
    //Y를 순회 하면서 map에 값이 있고 숫자가 1이상일 경우 vector에 넣는다.
    for(char c:Y){
        //map에 값이 있는 경우
        if(map.find(c)!=map.end()){
            if(map[c]>=1){
                vec.push_back(c);
                map[c]-=1; //1감소
            }
        }
    }
    
    
    //vector를 내림차순 으로 정렬 후 string으로 만든다.
    sort(vec.begin(),vec.end(),greater<char>());
    
    for(char c :vec){
        if(answer =="0")
            break;
        answer+=c;
    }
    
    if(answer =="")
        return "-1";
    
    return answer;
}