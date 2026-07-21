import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            char[] s = sc.next().toCharArray();
            Arrays.sort(s);
            if ( s[0] == 'a' && s[1] == 'b' && s[2] == 'c' ) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
