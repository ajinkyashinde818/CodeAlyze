import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        final char[] S = sc.next().toCharArray();
        final char[] T = sc.next().toCharArray();

        Arrays.sort(S);
        Arrays.sort(T);

        final String sAsc = new String(S);
        final String tDesc = new StringBuilder(new String(T)).reverse().toString();
        
        System.out.println(sAsc.compareTo(tDesc) < 0 ? "Yes" : "No");
    }
}
