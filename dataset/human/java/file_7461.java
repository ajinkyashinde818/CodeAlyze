import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String s = scan.next();
        s = s.replaceAll("eraser", "");
        s = s.replaceAll("erase", "");
        s = s.replaceAll("dreamer", "");
        s = s.replaceAll("dream", "");
        System.out.println(s.length() == 0 ? "YES" : "NO");
    }
}
