import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        String S = sc.next();
        sc.close();

        int[] count = new int[3];
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'a') {
                count[0]++;
            }
            if (S.charAt(i) == 'b') {
                count[1]++;
            }
            if (S.charAt(i) == 'c') {
                count[2]++;
            }
        }
        if (count[0] == 1 && count[1] == 1 && count[2] == 1) {
            out.printf("Yes\n");
        }
        else {
            out.printf("No\n");
        }
        out.flush();
    }
}
