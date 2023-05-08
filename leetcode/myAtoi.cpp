// beat most solutions using bitshift
// https://leetcode.com/problems/string-to-integer-atoi/submissions/946834462/
#include <cstdint>
class Solution {
public:
    int myAtoi(string s) {
        int left = -1;
        int right = -1;
        int sign = 1;
        int64_t answer = 0L;
        for (int i=0; i<s.size(); i++) {
            if (left == -1 && (isdigit(s[i]) || s[i] == '+' || s[i] == '-')) {
                if (s[i] == '-') {
                    sign = -1;
                } else if (isdigit(s[i])) {
                    answer = (int64_t) (((int) s[i]) - 48);
                }
                left = i;
            } else if (left == -1 && s[i] != ' ') {
                return 0;
            }
        }
        if (left > -1) {
            int i = left+1;
            while (i<s.size() && isdigit(s[i])) {
                answer = (answer << 3) + (answer << 1); // a^10
                answer += (int64_t) (((int) s[i]) - 48);
                if (answer > 2147483647 && sign > 0) {
                    return 2147483647;
                } else if (answer > 2147483648 && sign < 0) {
                    return -2147483648;
                }
                i++;
            }
            answer *= sign;
            if (answer > 2147483647) {
                return 2147483647;
            } else if (answer < -2147483648) {
                return -2147483648;
            } else {
                return (int)answer;
            }
        }
        return 0;
    }
};