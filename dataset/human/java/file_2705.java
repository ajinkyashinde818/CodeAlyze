import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        Arrays.sort(s);
        String ss = new String(s);
        Arrays.sort(t);
        String tt = new String(t);
        tt = new StringBuilder(tt).reverse().toString();
        if(ss.compareTo(tt) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
