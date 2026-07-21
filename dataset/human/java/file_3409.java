import java.io.IOException;
import java.util.Scanner;

/**
 * Created on 2017/10/25 7:00.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String s = sc.next();
            System.out.println(s.contains("9") ? "Yes" : "No");
        }
    }
}
