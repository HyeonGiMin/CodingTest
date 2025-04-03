// 숫자 카드 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/135807
// reference : https://park-peanut.tistory.com/193
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getGcdInArray(vector<int> &arr)
{
    int n1 = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int n2 = arr[i];
        while (true)
        {
            int n3 = n2 % n1;
            if (n3 == 0)
                break;
            n2 = n1;
            n1 = n3;
        }
    }

    return n1;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;

    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    // 각 Array의 최대 공약수
    int maxA = getGcdInArray(arrayA);
    int maxB = getGcdInArray(arrayB);

    // 조건을 만족하는지 비교
    answer = max(maxA, maxB);

    // A가 선택되었을 경우
    if (answer == maxA)
    {
        // 해당값이 B로 나눠지는 확인
        for (auto n : arrayB)
        {
            if (n % answer == 0)
                return 0;
        }
    }
    else
    {
        // B가 선택되었을 경우 해당값이 A로 나눠지는지 확인
        for (auto n : arrayA)
        {
            if (n % answer == 0)
                return 0;
        }
    }

    return answer;
}