import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            // 標準入力
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            int x = Integer.parseInt(br.readLine());
            if (x >= 1200) {
                System.out.println("ARC");
            } else {
                System.out.println("ABC");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
