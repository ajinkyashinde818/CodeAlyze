import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String s = in.next();
        String ans = (s.charAt(0) == '9' || s.charAt(1) == '9') ? "Yes": "No";
        System.out.println(ans);
    }
}
