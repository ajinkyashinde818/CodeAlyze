import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nr = br.readLine().split(" ");
        int n = Integer.parseInt(nr[0]);
        int r = Integer.parseInt(nr[1]);
        System.out.println(problem156a(n, r));
    }

    private static int problem156a(int n, int r) {
        return (n >= 10) ? r : (r + 100 * (10 - n));
    }
}
