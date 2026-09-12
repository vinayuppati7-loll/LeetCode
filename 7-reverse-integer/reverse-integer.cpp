class Solution {
public:
    int reverse(int x) {

        int revNum = 0;

        while (x != 0) {

            int ld = x % 10;

            // Positive overflow
            if (revNum > INT_MAX / 10 ||
               (revNum == INT_MAX / 10 && ld > 7))
                return 0;

            // Negative overflow
            if (revNum < INT_MIN / 10 ||
               (revNum == INT_MIN / 10 && ld < -8))
                return 0;

            revNum = revNum * 10 + ld;
            x /= 10;
        }

        return revNum;
    }
};