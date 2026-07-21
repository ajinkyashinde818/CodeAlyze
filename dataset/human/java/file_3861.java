import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int l = 0;
        int r = 0;
        int n = s.length();
        int count = 0;
        while (l < n - 1 - r) {
            if (s.charAt(l) == s.charAt(n - 1 - r)) {
                l++;
                r++;
            } else {
                if (s.charAt(l) == 'x') {
                    l++;
                    count++;
                } else if (s.charAt(n - 1 - r) == 'x') {
                    r++;
                    count++;
                } else {
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(count);
    }

}
