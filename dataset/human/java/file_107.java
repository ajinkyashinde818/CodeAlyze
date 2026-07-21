import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        int negativeNumCnt = 0;
        long absMin = Long.MAX_VALUE;
        long absSum = 0;
        boolean hasZero = false;
        for (int i = 0; i < N; i++) {
            if (A[i] == 0) {
                hasZero = true;
            }
            if (A[i] < 0) {
                negativeNumCnt++;
            }
            long abs = Math.abs(A[i]);
            absSum += abs;
            if (abs < absMin) {
                absMin = abs;
            }
        }

        if (negativeNumCnt %2 == 0 || hasZero == true) {
            System.out.println(absSum);
        }
        else {
            long max = absSum - absMin * 2;
            System.out.println(max);
        }
    }
}
