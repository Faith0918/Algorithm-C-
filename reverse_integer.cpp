#include<cmath>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        int a = 0;
        int number = x;
        int reverse_number = 0;
        // 0. 부호 확인하기
        if (INT_MIN / 10 >= number / 10 || number / 10 > INT_MAX / 10) {
            return 0;
        }
        if (x < 0) {
            sign = -1;
            number *= -1;
        }
        


        bool flag = false;
        
        while (number % 10 >= 0 && (number / 10) >= 0) {
            if (number == 0) {
                break;
            }
            // 0-2. overflow 확인하기
            if (reverse_number > INT_MAX / 10 || (reverse_number == INT_MAX / 10 && a >= INT_MAX % 10)) {
                return 0;
            }
            if (number / 10 == 0 && number % 10 > 0) {
                reverse_number = reverse_number * 10 + number;
                number = number / 10;
                break;
            }


            
            if (number % 10 > 0) {
                flag = true;
                // 1. number의 0이 아닌 가장 낮은 자리 수 a 찾기
                a = number % 10;
                // 2. 새로운 숫자 reverse_number * 10 + a 저장
                reverse_number = reverse_number * 10 + a;
                // 3. number = (number - a) / 10
                number = number / 10;
            }
            else if (!flag) {
                a = 0;
                number = number / 10;
            }
            else {
                a = 0;
                reverse_number = reverse_number * 10;
                number = (number) / 10;
            }
            // 4. 1번으로 돌아가기.
        }
        return sign * reverse_number;
    }
};