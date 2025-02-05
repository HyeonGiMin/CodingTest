//신규 아이디 추천
//https://school.programmers.co.kr/learn/courses/30/lessons/72410
//https://wadekang.tistory.com/13
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string ReplaceAll(string &str,const string& from,const string& to){
    size_t start_pos=0;
    
    while((start_pos=str.find(from,start_pos))!=string::npos){
        str.replace(start_pos,from.length(),to);
        start_pos+=to.length();
    }
          
    return str;
};

string solution(string new_id) {
    string answer = "";
    string tmp="";
    
    //01. 소문자로 치환
    for(int i=0;i<new_id.size();i++){
        new_id[i] = tolower(new_id[i]);
    }
    
    //02.알파벳 소문자, 숫자, 빼기, 밑줄,마침포를 제외한 모든 문자를 제거
    for(int i=0;i<new_id.size();i++){
        char c = new_id[i];
        //소문자인지 확인
        if(c>='a' && c<='z'){
            tmp+=c;
        }else if( c>='0' && c<='9'){ //숫자인지 확인
            tmp+=c;
        }else if(c =='-' || c=='_' || c =='.'){
            tmp+=c;
        }
    }
    new_id = tmp;
    tmp = "";
    //03. 마침표가 2번 이상 연속된 부분은 하나의 마침표로 치환
    //마지막 .만 추가
    for(char c:new_id){
        if(c=='.'&& tmp.back() == '.')
            continue;
        tmp+=c;
    }
    new_id = tmp;
    tmp = "";
    
    //04.마침표가 처음이거나 끝이면 제거
    if(new_id.front()=='.') new_id.erase(0,1);
    if(new_id.back() == '.') new_id.pop_back();
    
    //05.빈 문자열 이라면 a를 대입한다
    if(new_id.empty()) new_id='a';
    
    //06.16자리 이상일 경우 문자열을 자른다. 자른후 마지막 값이 마침표이면 제거 
    if(new_id.size()>=16) new_id.erase(new_id.begin()+15,new_id.end());
    if(new_id.back() == '.') new_id.pop_back();
    
    //07. 길이가 2자 이하라면 마지막 문자를 길이가 3이 될때까지 붙인다.
    while(new_id.size()<3){
        new_id+=new_id.back();
    }
    
    return new_id;
}
