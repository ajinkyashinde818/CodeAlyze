import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) throws Exception {

        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();

        char[] s2 = s.toCharArray();
        char[] t2 = t.toCharArray();

        Arrays.sort(s2);
        Arrays.sort(t2);

        String s3 = "";
        String t3 = "";

        for (int i = 0; i < s.length(); i++) {
            s3 += s2[i];
        }
        for (int i = 0; i < t.length(); i++) {
            t3 += t2[t.length() - i - 1];
        }

        if (s3.compareTo(t3) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }
}
