public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        while (true) {
            int mid = (n - low) / 2 + low;
            switch (super.guess(mid)) {
                case -1:
                    n = mid - 1;
                    break;
                case 0:
                    return mid;
                case 1:
                    low = mid + 1;
                    break;
            }
        }
    }
}
