//150370
//https://school.programmers.co.kr/learn/courses/30/lessons/150370
//reference: https://confluence.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4C2023-KAKAO-BLIND-RECRUITMENT-%EA%B0%9C%EC%9D%B8%EC%A0%95%EB%B3%B4-%EC%88%98%EC%A7%91-%EC%9C%A0%ED%9A%A8%EA%B8%B0%EA%B0%84
#include <string>
#include <vector>
#include <sstream>
#include <map>
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

vector<int> splitToInt(const string& input, char delimeter){
    vector<int> result;
    stringstream ss(input);
    string item;
    
    while(getline(ss,item,delimeter)){
        result.push_back(stoi(item));
    }
    
    return result;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> todayVec = splitToInt(today, '.');
    map<string, int> map;
    //오늘 날짜와 수집일자 + 유효기간 을 비교하여 파기해야할 대상을 지정
    int todayInt = ((todayVec[0] - 2000) * 12 * 28) + (todayVec[1] * 28) + todayVec[2];



    //01. 약관을 맵으로 만든다.
    //약관종류, 기간(달)
    for (string term : terms) {
        vector<string> sVec = split(term, ' ');

        map.insert(make_pair(sVec[0], stoi(sVec[1])));
    }

    int id = 0;
    for (string privacie : privacies) {
        id += 1;
        //수집일자랑 약관 종류를 분리 
        vector<string> sVec = split(privacie, ' ');
        int termsDate = map[sVec[1]];

        //날짜를 파싱 
        vector<int> date = splitToInt(sVec[0], '.');

        //날짜에 약관 달을 더한다
        date[1] += termsDate;

        //날짜를 일로 변환
        int termsDay = ((date[0] - 2000) * 12 * 28) + (date[1] * 28) + date[2]-1;

        if (termsDay < todayInt)
            answer.push_back(id);


    }


    return answer;
}