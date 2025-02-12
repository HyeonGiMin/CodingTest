//이진 변환 반복하기
//https://school.programmers.co.kr/learn/courses/30/lessons/70129
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int removeCnt=0;
    int convertCnt = 0;
    
    while(s != "1"){
        string tmp = "";
        //remove '0'
        for(char c: s){
            if(c == '0')
                removeCnt++;
            else
                tmp+=c;
        }
        
        //2진법 변환
        string binary;
        int n =tmp.size();
        while(n!=0){
            binary+=to_string(n%2);
            n/=2;
        }
        
        reverse(binary.begin(),binary.end());
        
        s= binary;
        convertCnt++;
    }
    
  
    answer.push_back(convertCnt);
    answer.push_back(removeCnt);
    
    return answer;
}