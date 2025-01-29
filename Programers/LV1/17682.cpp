//[1차] 다트게임  https://school.programmers.co.kr/learn/courses/30/lessons/17682

#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> vec;
    int idx=0;
    
    //1.숫자 기준으로 다음 숫자가 나올때까지가 1세트
    //S,D,T의 경우 Vector에 추가
    string tmp="";
    for(int i=0;i<dartResult.size();i++){
        char c = dartResult[i];
        if(c>='0' && c<='9'){
            tmp+=c;
        }else if(c == 'S'){
            int num =stoi(tmp);
            vec.push_back(num);
            tmp=""; //clear
            idx++;
        }else if(c=='D'){
            int num =stoi(tmp);
            vec.push_back(num*num);
            tmp=""; //clear
            idx++;
        }else if(c == 'T'){
            int num =stoi(tmp);
            vec.push_back(num*num*num);
            tmp=""; //clear
            idx++;
        }else if(c == '*'){
            if(idx == 1){
                vec[idx-1] *=2;
            }else{
                vec[idx-1] *=2;
                vec[idx-2] *=2;
            }
        }else if(c== '#'){
            vec[idx-1] = -1* vec[idx-1];
        }
    }
    
    for(auto v : vec){
        answer+=v;
    }

    
    return answer;
}