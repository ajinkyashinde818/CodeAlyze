import java.util.Scanner;

public class Main {
    public static void main(final String[] args) {
        final int p = 2;
        switch (p) {
        case 2:
            B.answer();
            break;
        case 1:
            A.answer();
            break;
        }
    }
}

class B {

    static void answer() {
        final Scanner sc = new Scanner(System.in);
        final int n = sc.nextInt();
        final int[] arrayA = new int[n];
        for (int i = 0; i < n; i++) {
            arrayA[i] = sc.nextInt();
        }
        final int[] arrayB = new int[n];
        for (int i = 0; i < n; i++) {
            arrayB[i] = sc.nextInt();
        }
        final int[] arrayC = new int[n];
        for (int i = 0; i < n - 1; i++) {
            arrayC[i] = sc.nextInt();
        }
        final int res = calc(arrayA, arrayB, arrayC);
        System.out.println(res);
    }

    static int calc(final int[] arrayA, final int[] arrayB, final int[] arrayC) {
        int total = 0;
        int prevRyori = -100;
        for (int i = 0; i < arrayA.length; i++) {
            final int ryoriNo = arrayA[i];
            final int manpuku = arrayB[ryoriNo - 1];
            total += manpuku;
            if (ryoriNo - prevRyori == 1) {
                total += arrayC[prevRyori - 1];
            }
            prevRyori = ryoriNo;
        }

        return total;
    }
}
class A {
    static void answer() {
        final Scanner sc = new Scanner(System.in);
        final int n = sc.nextInt();
        final int res = calc(n);
        System.out.println(res);
    }

    static int calc(final int n) {
        return n * n * n;
    }
}
