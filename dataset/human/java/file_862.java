import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int r = Integer.parseInt(inputs[1]);
        
        int ans = n < 10 ? r + 100 * (10 - n) : r;

        pw.println(ans);
        pw.flush();
    }
}
