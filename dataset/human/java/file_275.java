import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.LongStream;

public class Main {

    public static void main(String[] args) {

        execute();
    }

    private static void execute() {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] A = new long[N];
        long[] AbsM = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
            AbsM[i] = Math.abs(A[i]);
        }

        long negativeCount = LongStream.of(A).filter(s -> s < 0).count();
        long absAmount = LongStream.of(AbsM).reduce(0, (s1, s2) -> s1 + s2);

        if (negativeCount % 2 == 0) {
            System.out.println(absAmount);
        } else {
            Arrays.sort(AbsM);
            System.out.println(absAmount - AbsM[0] * 2);
        }
    }

}
