//오픈채팅방
//https://school.programmers.co.kr/learn/courses/30/lessons/42888
//reference: https://jinho082008.tistory.com/25
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(const string& input, char delimeter) {
    vector<string> result;
    stringstream ss(input);
    string item;

    while (getline(ss, item, delimeter)) {
        result.push_back(item);
    }

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;

    //마지막 id 기준으로 동작
    map<string, string> idMap;

    //status, id 
    vector<pair<string, string>> statusV;

    for (string r : record) {

        //공백 기준으로 파싱;
        vector<string> s = split(r, ' ');

        string status = s[0];
        string uid = s[1];

        statusV.push_back({ status,uid });


        if (status == "Enter" || status == "Change") {
            string nickname = s[2];
            idMap[uid] = nickname;
        }

    }

    //메시지 출력
    for (auto p : statusV) {
        if (p.first == "Enter") {
            answer.push_back(idMap[p.second] + "님이 들어왔습니다.");
        }
        else if (p.first == "Leave") {
            answer.push_back(idMap[p.second] + "님이 나갔습니다.");
        }
    }




    return answer;
}
