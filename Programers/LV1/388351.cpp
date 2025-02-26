#include <string>
#include <vector>

using namespace std;

int covertToMinute(int schedules){
    int hour = schedules/100;
    int minute = schedules%100;
    
    return minute+(hour*60);
    
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    vector<int> date;

    //시작은 시에 100을 곱하고 분을 더한 정수
    //시간을 분으로 나누려면 100으로 나누고 * 60;

    //01. schedules을 분 단위로 변환
    for (int i = 0; i < schedules.size(); i++) {
        schedules[i] = covertToMinute(schedules[i]);
    }

    //02. 확인해야 하는 날짜를 별도의 배열로 생성
    for (int i = 0; i < 7; i++) {
        startday = startday % 8;
        if(startday == 0)
            startday = 1;
        int now = startday;
        date.push_back(now);
        startday++;
    }


    //03. 사용자별로 시간 비교
    for (int i = 0; i < timelogs.size(); i++) {
        //해당 사용자의 기준 시간 schedules[i];
        int schedule = schedules[i];
        bool success = true;

        //해당 사용자의 timelog를 
        for (int j = 0; j < timelogs[i].size(); j++) {
            //날짜를 확인
            if (date[j] == 6 || date[j] == 7)
                continue;

            //시간이 기준시간보다 +10 이상인 경우 false로 바꾸고 종료
            int time = covertToMinute(timelogs[i][j]);
            if (time > schedule + 10) {
                success = false;
                break;
            }

        }

        //실패하지 않았다면 추가
        if (success)
            answer++;

    }


    return answer;
}