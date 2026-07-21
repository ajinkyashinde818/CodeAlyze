import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        System.out.println( solve(S) );
    }

    private static String solve(String S) {
        String s = reverse(S);
        String t1 = reverse("dream");
        String t2 = reverse("dreamer");
        String t3 = reverse("erase");
        String t4 = reverse("eraser");
        int i = 0;

        while(true) {
            i = nextIndexOf(s, i, t1, t2, t3, t4);
            if( i == -1 ) return "NO";
            if( i == s.length() ) return "YES";
        }
    }

    private static String reverse(String s) {
        char[] rev = new char[s.length()];
        for (int i = 0, j = s.length() -1; i < s.length(); i++, j--) {
            rev[j] = s.charAt(i);
        }
        return new String(rev);
    }

    private static int nextIndexOf(String s, int i, String... ts) {
        for (String t : ts) {
            if( s.startsWith(t, i) ) {
                return i + t.length();
            }
        }
        return -1;
    }
}
