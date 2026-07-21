import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(System.in);
        StringBuilder s = new StringBuilder(scanner.next());
        StringBuilder left = new StringBuilder();
        StringBuilder right = new StringBuilder();
        final long q = scanner.nextLong();
        int rev = 0;
        String qi;
        int fi;
        for (int i = 0; i < q; i++) {
            qi = scanner.next();
            if (qi.equals("1")) {
                rev++;
            } else {
                fi = scanner.nextInt();
                if (fi == 1) {
                    if (rev % 2 == 0) {
                        left.insert(0,scanner.next());
                    } else {
                        right.append(scanner.next());
                    }
                } else {
                    if (rev % 2 == 0) {
                        right.append(scanner.next());
                    } else {
                        left.insert(0,scanner.next());
                    }
                }
            }
        }
        if (rev % 2 == 1) {
            s.reverse();
            System.out.println("" + right.reverse() + s + left.reverse());
        } else {
            System.out.println("" + left + s + right);
        }
    }
}
