import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long k = scanner.nextLong();
        long n = scanner.nextLong();
        long max = -1;
        long maxValue = -1;
        List<Long> hs = new ArrayList<>();
        long last = 0;
        long first = -1;
        long c = Long.MIN_VALUE;
        long count = -1;
        for (int i = 0; i < n; i++) {
            c = scanner.nextLong();
            hs.add(c);
            count++;
            if (first == -1) {
                first = c;
                last = c;
            } else {
                if (c - last > maxValue) {
                    maxValue = c - last;
                    max = count;
                }
                last = c;
            }
        }
        if (maxValue < k - c + first) {
            maxValue = k - c + first;
            max = 1;
        }
        if (max == n-1) {
            if (maxValue < hs.get(0) + k - hs.get(hs.size()-1)) {
                System.out.println(hs.get(hs.size()-1));
                return;
            }
        }
        if (max == 1) {
            System.out.println(hs.get(hs.size()-1) - hs.get(0));
            return;
        }
        long f = hs.get(Math.toIntExact(max - 1));
        long l = k - hs.get(Math.toIntExact(max));
        long r = f + l;
        System.out.println(r);
    }

}
