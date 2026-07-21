import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.next());
        long k = Long.parseLong(scan.next());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(scan.next());
            a[i]--;
        }
        scan.close();

        int[] arrive = new int[n];
        boolean[] isUsed = new boolean[n];
        Arrays.fill(isUsed, false);
        arrive[0] = 0;
        isUsed[0] = true;
        int breakTown = 0;
        int breakIndex = 0;
        for (int i = 1; i <= n; i++) {
            int next = a[arrive[i - 1]];
            if (isUsed[next]) {
                breakTown = next;
                breakIndex = i;
                break;
            }

            isUsed[next] = true;
            arrive[i] = next;
        }

        int loopStartIndex = 0;
        for (int i = 0; i < n; i++) {
            if (arrive[i] == breakTown) {
                loopStartIndex = i;
                break;
            }
        }

        int loopLength = breakIndex - loopStartIndex;
        if (k <= loopStartIndex) {
            System.out.println(arrive[(int)k] + 1);
        } else {
            long index = (k - loopStartIndex) % loopLength;
            System.out.println(arrive[(int)index + loopStartIndex] + 1);
        }

    }
}
