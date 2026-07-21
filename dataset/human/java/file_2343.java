import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int idx = str.lastIndexOf("FESTIVAL");

        String ans = "";
        for (int i = 0; i < idx; i++) {
            ans += str.charAt(i);
        }

        System.out.println(ans);
    }
}
