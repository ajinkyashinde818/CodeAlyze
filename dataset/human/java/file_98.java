import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner std = new Scanner(System.in);
        int N = std.nextInt();
        int[] A = IntStream.range(0, N).map(it -> std.nextInt()).toArray();
        long minusCount = Arrays.stream(A).filter(it -> it < 0).count();
//        long BMax = 0;
        BigInteger BMax = BigInteger.valueOf(0L);
        if (minusCount % 2 == 0) {
            int[] s = Arrays.stream(A).map(Math::abs).toArray();
            for (int i = 0; i < s.length; i++) {
                BMax = BMax.add(BigInteger.valueOf(s[i]));
            }
        } else {
            int[] arrays = Arrays.stream(A).map(Math::abs).sorted().toArray();
            int min = arrays[0];
            for (int i = 1; i < arrays.length; i++) {
                BMax = BMax.add(BigInteger.valueOf(arrays[i]));
            }

            BMax = BMax.subtract(BigInteger.valueOf(min));
        }

        System.out.println(BMax.toString());
    }
}
