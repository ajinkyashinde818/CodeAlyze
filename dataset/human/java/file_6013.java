import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String w = cin.next();
        char[] clist = w.toCharArray();
        Arrays.sort(clist);
        System.out.println(Arrays.equals(clist, new char[] {'a', 'b', 'c'}) ? "Yes" : "No");
    }
}
