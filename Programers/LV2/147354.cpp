// 테이블 해시 함수
// https://school.programmers.co.kr/learn/courses/30/lessons/147354
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    vector<int> v;
    int x = col - 1;

    // 정렬을 각 Row의 col-1번째 값 기준으로 오름차순 정렬
    sort(data.begin(), data.end(), [x](const vector<int> &a, const vector<int> &b)
         {
        if (a[x] == b[x])
            return a[0] > b[0];

        return a[x] < b[x]; });

    for (int i = row_begin; i <= row_end; i++)
    {
        // s_i 는 각 컬럼의 값을 i로 나눈 나머지의 합
        int sum = 0;

        for (int n : data[i - 1])
        {
            sum += (n % i);
        }
        v.emplace_back(sum);
    }

    // 누적하여 bitwiseXOR 수행
    answer = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        answer = answer ^ v[i];
    }

    return answer;
}