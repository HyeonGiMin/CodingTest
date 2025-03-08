//모음사전
//https://school.programmers.co.kr/learn/courses/30/lessons/84512
//reference: https://fulladdr.tistory.com/53
#include <string>
#include <vector>

using namespace std;
string aeiou = "AEIOU";
int count,answer=0;

void DFS(string curWord,string word){
    if(curWord ==word){
        answer=count;
        return;
    }
    
    if(curWord.length()>=5){
        return;
    }
    
    for(int i=0;i<aeiou.size();i++){
        count++;
        DFS(curWord+aeiou[i],word);
    }
        
}

int solution(string word) {
     DFS("", word);
    
    
    return answer;
}