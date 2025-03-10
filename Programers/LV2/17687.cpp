//[3차] n진수 게임
//https://school.programmers.co.kr/learn/courses/30/lessons/17687
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char format[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//
string convertFormat(int n,int max){
    //수샂 0부터 n진법으로 변환하여 문자열의 길이가 max가 될때까지 변환하여 붙인다
    string result="";
    int idx=0;
    while(true){
        
        if(idx==0)
        {
            result+=format[idx];
        }else{
            string tmp;
            //idx를 n진법으로 변환
            int i = idx;
            while(i!=0){
                tmp+=format[i%n];
                i/=n;
            }
            
            reverse(tmp.begin(),tmp.end());
            result+=tmp;
        }
        
        //길이가 더 커지면 break;
        if(result.size()>max)
            break;
        
        idx++;
    }
    
    return result;
} 


string solution(int n, int t, int m, int p) {
    string answer = "";
    
    //최대 m*t;
    //문자열의 길이가 m*t일때 까지 변환
    
    string str =convertFormat(n,t*m);
    
    //말해야 하는 숫자는 p-1, p-1+m,p-1+m+m .....
    int idx=p-1;
    for(int i=0;i<t;i++){
        answer+=str[idx];
        idx+=m;
    }
    
    
    return answer;
}