//영어 끝말잇기
//https://school.programmers.co.kr/learn/courses/30/lessons/12981
//refrernce https://velog.io/@aoleejohn/C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%98%81%EC%96%B4-%EB%81%9D%EB%A7%90%EC%9E%87%EA%B8%B0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0); //0으로 초기화
    map<string,bool> map;
    string prev="";
    int failIdx=0;

    for(int i=0;i<words.size();i++){
        string word= words[i];
        //사용 여부 확인 및 앞 단어의 마지막 글자와 확인 
        if(map[word] || (prev!= "" && prev.back() != word.front())){
            failIdx=i;
            break;
        }
        prev=word;
        map[word] = true;

    }
    
    if(failIdx!=0){
        answer[0] = (failIdx % n) + 1;
        answer[1] = failIdx / n + 1;
    }

    return answer;
}