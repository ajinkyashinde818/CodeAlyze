import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        Arrays.sort(s);

        System.out.println( new String(s).equals("abc")?"Yes":"No" );
    }
}
