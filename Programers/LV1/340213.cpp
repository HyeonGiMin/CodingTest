//[PCCP 기출문제] 1번 / 동영상 재생기
//https://school.programmers.co.kr/learn/courses/30/lessons/340213
#include <string>
#include <vector>

using namespace std;


int ConvertTimeToSecond(string time){
    string m = time.substr(0,2);
    string s = time.substr(3,2);
    
    return stoi(s)+(60*stoi(m));
}



string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    //모두 초로 바꿔서 처리
    int nVideoLen,nPos,nOpStart,nOpEnd;
    nVideoLen=ConvertTimeToSecond(video_len);
    nPos=ConvertTimeToSecond(pos);
    nOpStart=ConvertTimeToSecond(op_start);
    nOpEnd=ConvertTimeToSecond(op_end);
    
     //Execute Command
   for (auto command : commands) {

       //현재 위치가 오프닝 구간일 경우 자동으로 오프닝 끝나는 위치로 이동
       if (nPos >= nOpStart && nPos <= nOpEnd)
           nPos = nOpEnd;

       if (command == "prev") {
           nPos -= 10;
       }
       else if (command == "next") {
           nPos += 10;
       }
       
        //현재 위치가 오프닝 구간일 경우 자동으로 오프닝 끝나는 위치로 이동
        if (nPos >= nOpStart && nPos <= nOpEnd)
            nPos = nOpEnd;

       //현재 위치가 음수일 경우 0으로 이동
       if (nPos <= 0)
           nPos = 0;

       //영상의 길이를 넘을 경우 마지막 위치로
       if (nPos > nVideoLen)
           nPos = nVideoLen;
     
   }
    
    
    int nMin = nPos/60;
    int nSec = nPos%60;
    
    string minute = to_string(nMin);
    string second = to_string(nSec);
        
    if(minute.size()==1)
        minute='0'+minute;
        
    if(second.size()==1)
        second = '0'+second;
        
    answer = minute + ':'+ second;
        
    
    return answer;
}