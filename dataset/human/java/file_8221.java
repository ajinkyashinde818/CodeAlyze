import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        long A;
        long B;
        long ans;

        Scanner sc = new Scanner(System.in);
        A = sc.nextInt();
        B = sc.nextInt();
        ans = A * B / div(A, B);
        System.out.println(ans);
    }

    public static long div(long i, long j) {
        long l, s;
        if (i>j) { l = i; s = j;}
        else {s = i; l = j;}
        if (l % s != 0) return div(s, l%s);
        else return s;
    }
}
