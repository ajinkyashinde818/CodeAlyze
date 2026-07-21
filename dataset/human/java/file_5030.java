import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int Q = Integer.parseInt(sc.next())	;
        StringBuilder str = new StringBuilder(S);
        StringBuilder left = new StringBuilder();
        StringBuilder right = new StringBuilder();

        boolean reverse = false;
        for (int i = 0; i < Q; i++) {
            int T = sc.nextInt();
            reverse = T == 1 ? !reverse : reverse;
            if (T == 1) {
                continue;
            }
            int F = Integer.parseInt(sc.next())	;
            char C = sc.next().charAt(0);
            if (F == 1) {
                if (reverse) {
                    right.append(C);
                    continue;
                }

                left.insert(0, C);
                continue;
            }
            if (reverse) {
                left.insert(0, C);
                continue;
            }
            right.append(C);
        }
        System.out.println(reverse ? str.append(right).insert(0,left).reverse(): str.append(right).insert(0,left));
    }
}
