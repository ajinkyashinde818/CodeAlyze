import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] ss = s.split("");
        Arrays.sort(ss);
        if (String.join("", ss).equals("abc")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
