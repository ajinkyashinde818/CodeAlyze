import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char[] str = in.nextLine().toCharArray();
        Arrays.sort(str);
        if("abc".equals(String.valueOf(str))) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
