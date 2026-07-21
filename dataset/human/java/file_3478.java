import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            // 標準入力
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            String str[] = br.readLine().split(" ");
            char x = str[0].charAt(0);
            char y = str[1].charAt(0);
            if (x > y) {
                System.out.println(">");
            } else if (x < y) {
                System.out.println("<");
            } else {
                System.out.println("=");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
