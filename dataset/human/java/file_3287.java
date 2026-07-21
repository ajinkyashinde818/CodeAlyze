import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        String s = Integer.toString(N);
        boolean found = false;
        for (char c : s.toCharArray()) {
            if (c == '9') {
                found = true;
                break;
            }
        }
        System.out.println(found ? "Yes" : "No");
    }
}
