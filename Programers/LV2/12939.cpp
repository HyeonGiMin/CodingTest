//최댓값과 최솟값
//https://school.programmers.co.kr/learn/courses/30/lessons/12939
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(const string& input, char delimeter){
    vector<string> result;
    stringstream ss(input);
    string item;
    
    while(getline(ss,item,delimeter)){
        result.push_back(item);
    }
    
    return result;
}

bool comp(string a,string b){
    int aInt = stoi(a);
    int bInt = stoi(b);
    
    return aInt<bInt;
}

string solution(string s) {
    string answer = "";
    //공백 기준으로 분리
    vector<string> v = split(s,' ');
    
    //정렬 해서 첫번째 요소가 최솟값, 마지막 요소가 최댓값
    sort(v.begin(),v.end(),comp);
    string min = v.front();
    string max = v.back();
    answer = min + " "+ max;
    
    return answer;
}