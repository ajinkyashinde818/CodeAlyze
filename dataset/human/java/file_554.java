import java.util.Scanner;

/**
 * TITLE : Beginner
 * URL : https://atcoder.jp/contests/abc156/tasks/abc156_a
 */
public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int R = sc.nextInt();
        int answer = N >= 10 ? R : R + 100 * (10 - N);
        System.out.println(answer);
        sc.close();
    }
}
