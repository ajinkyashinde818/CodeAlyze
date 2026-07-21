import java.util.Scanner;

public class Main {
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int negativeCount = 0;
        long minNum = Long.MAX_VALUE;
        long absSum = 0L;
        for (int i = 0; i < N; i++) {
            long a_i  = sc.nextLong();
            long abs = Math.abs(a_i);
            if (a_i < 0L) {
                negativeCount++;
            }
            absSum += abs;
            if (abs < minNum) {
                minNum = abs;
            }
        }
        System.out.println(negativeCount % 2 == 0 ? absSum : absSum - 2L * minNum);
    }
}
