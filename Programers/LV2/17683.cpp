//[3차] 방금그곡
// https://school.programmers.co.kr/learn/courses/30/lessons/17683#
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

vector<string> split(const string &input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string item;

    while (getline(ss, item, delimiter))
    {
        result.emplace_back(item);
    }

    return result;
}

string convertSharp(string str)
{
    string result = "";
    for (int i = 0; i < str.size(); i++)
    {
        // 현재 값이 #일 경우 result의 마지막값(이전값)을 소문자로 변경
        if (str[i] == '#')
        {
            result.back() = tolower(result.back());
        }
        else
        {
            result += str[i];
        }
    }

    return result;
}

int convertToMinute(string time)
{
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);

    return stoi(hour) * 60 + stoi(min);
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "";
    int answerTime = 0;

    m = convertSharp(m);

    for (string musicinfo : musicinfos)
    {
        vector<string> v = split(musicinfo, ',');
        string sTime = v[0];
        string eTime = v[1];

        string name = v[2];
        string score = v[3];
        score = convertSharp(score);

        int nSTime = convertToMinute(sTime);
        int nETime = convertToMinute(eTime);

        int diff = nETime - nSTime;

        // 재생된 내용
        int scoreLen = score.size();

        if (scoreLen < diff)
        {
            int remain = diff - scoreLen;
            int idx = 0;
            string orgScore = score;
            while (remain > 0)
            {
                score += orgScore[idx];
                idx++;
                idx %= scoreLen;
                remain--;
            }
        }

        // 전체 재생이 안된 경우
        if (scoreLen > diff)
        {
            score = score.substr(0, diff);
        }

        if (score.find(m) != string::npos)
        {

            // 값이 있을 경우 재생시간이 제일 긴 음악 제목 반환
            if (answerTime < diff)
            {
                // 더 길 경우 answer의 값 변경
                answer = name;
                answerTime = diff;
            }
        }
    }

    if (answer.empty())
        answer = "(None)";

    return answer;
}