//[3차] 압축
//https://school.programmers.co.kr/learn/courses/30/lessons/17684
//reference: https://park-peanut.tistory.com/196
#include <string>
#include <vector>
#include <map>


using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int idx=1;
    map<string,int> dic;
    
    //Set Default
    for(char c='A'; c<='Z';c++){
        string str ="";
        str+=c;
        dic[str]=idx++;
    }
    
    //현재 입력과 일치하는 가장 긴 문자열 찾기
    string w="";
    for(char c : msg){
        string wc= w+c;
        
        //map에 값이 존재 
        if(dic.find(wc) != dic.end()){
            w.clear();
            w+=wc;
        }else{
            //신규값은 사전에 등록
            dic[wc] = idx++;
            //기존 값 검색
            if(dic.find(w) !=dic.end()){
                answer.push_back(dic[w]);
                w.clear();
                w+=c;
            }
        }
    }
    
    //마지막 요소 확인
   if(dic.find(w) !=dic.end()){
        answer.push_back(dic[w]);
    }
    
    
    
    return answer;
}