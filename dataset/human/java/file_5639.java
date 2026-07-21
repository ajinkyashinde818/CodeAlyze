import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int n = cin.nextInt();
        int k = cin.nextInt();
        int s = cin.nextInt();

        int t = (s == 1000000000) ? s - 1 : s + 1;

        for (int i = 0; i < k; i++) System.out.printf("%d ", s);
        for (int i = k; i < n; i++) System.out.printf("%d ", t);
        System.out.println();
    }
}
