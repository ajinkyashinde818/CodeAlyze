import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        StringBuilder head = new StringBuilder();
        StringBuilder tail = new StringBuilder();
        int Q = sc.nextInt();
        boolean flag = true;
        for (int i = 0; i < Q; i++) {
            int qn = sc.nextInt();
            if (qn == 1 && flag == true) {
                flag = false;
            } else if (qn == 1 && flag == false) {
                flag = true;
            } else {
                int qn2 = sc.nextInt();
                if (flag == true) {
                    if (qn2 == 1) {
                        head.append(sc.next());
                    } else {
                        tail.append(sc.next());
                    }
                } else {
                    if (qn2 == 1) {
                        tail.append(sc.next());
                    } else {
                        head.append(sc.next());
                    }
                }

            }

        }
        // System.out.println(flag);
        S = head.reverse() + S + tail;
        if (flag == true) {
            System.out.println(S);
        } else {
            // System.out.println(flag);
            int tmp = S.length();
            char[] SC = S.toCharArray();
            for (int i = 0; i < S.length(); i++) {
                System.out.print(SC[tmp - 1 - i]);

            }
        }
    }
}
