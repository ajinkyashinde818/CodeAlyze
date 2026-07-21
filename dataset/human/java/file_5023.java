import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int q = sc.nextInt();
        int dir = 1;
        char[] l = new char[300000];
        char[] r = new char[300000];
        int lind = 0;
        int rind = 0;
        for (int i = 0 ; i < q ; i++) {
            int t = sc.nextInt();
            if (t == 1) {
                dir *= -1;
            } else {
                int f = sc.nextInt();
                char c = sc.next().toCharArray()[0];
                if (f == 2) {
                    if (dir == 1) {
                        l[lind] = c;
                        lind++;
                    } else {
                        r[rind] = c;
                        rind++;
                    }
                } else {
                    if (dir == 1) {
                        r[rind] = c;
                        rind++;
                    } else {
                        l[lind] = c;
                        lind++;
                    }
                }
            }
        }
        if (dir == 1) {
            for (int i = 0 ; i < rind ; i++) {
                System.out.print(r[rind - i - 1]);
            }
            System.out.print(s);
            for (int i = 0 ; i < lind ; i++) {
                System.out.print(l[i]);
            }
        } else {
            for (int i = 0 ; i < lind ; i++) {
                System.out.print(l[lind - i - 1]);
            }
            for (int i = 0 ; i < s.length() ; i++) {
                System.out.print(s.charAt(s.length()- i - 1));
            }
            for (int i = 0 ; i < rind ; i++) {
                System.out.print(r[i]);
            }
        }



    }

}
