// 연속된 부분 수열의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/178870
// reference : https://please-amend.tistory.com/294
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;

    int startIdx = 0;
    int endIdx = 0;

    int sum = sequence[0];

    while (startIdx <= endIdx && endIdx < sequence.size())
    {
        if (sum == k)
        {
            if (answer.empty() || answer[1] - answer[0] > endIdx - startIdx)
            {
                answer = {startIdx, endIdx};
            }
        }

        if (sum < k)
        {
            endIdx++;
            sum += sequence[endIdx];
        }
        else
        {
            sum -= sequence[startIdx];
            startIdx++;
        }
    }

    return answer;
}