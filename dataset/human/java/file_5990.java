import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        String result = "No";
        if (line.contains("a")) {
            if (line.contains("b")) {
                if (line.contains("c")) {
                    result = "Yes";
                }
            }
        }
        System.out.println(result);
    }
}
