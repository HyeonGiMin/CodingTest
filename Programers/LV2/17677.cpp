//[1차] 뉴스 클러스터링
//https://school.programmers.co.kr/learn/courses/30/lessons/17677
//reference: https://underdot.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4C1%EC%B0%A8%EB%89%B4%EC%8A%A4-%ED%81%B4%EB%9F%AC%EC%8A%A4%ED%84%B0%EB%A7%81
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> createLowerSet(string str){
    vector<string> v;
    string temp;
    for(int i=0;i<str.size();i++){
        char c = str[i];
        if(isalpha(c)){
            temp+=tolower(c);
        }else
            temp.clear();
        
        if(temp.size()==2){
            v.push_back(temp);
            temp.erase(temp.begin());
        }
    }
    
    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    //두글자씩 끊어서 소문자로 저장
    vector<string> arr1 = createLowerSet(str1);
    vector<string> arr2 = createLowerSet(str2);
    
    //A와 B가 모두 공집합일 경우 1로 정의
    if(arr1.size() ==0 && arr2.size()==0){
        return 65536;
    }
    
    //공통된 부분 구하기
    int interSection =0;
    for(auto i:arr1){
        auto idx = find(arr2.begin(),arr2.end(),i);
        if(idx != arr2.end()){
            interSection++;
            arr2.erase(idx);
        }
    }
    
    float result = (float)interSection/(arr1.size()+arr2.size()); 
    
    
    answer= result*65536;
    return answer;
}