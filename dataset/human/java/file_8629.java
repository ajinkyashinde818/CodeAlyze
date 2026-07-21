import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String[] arr = br.readLine().split(" ");
        int A = Integer.parseInt(arr[0]);
        int B = Integer.parseInt(arr[1]);
        int K = Integer.parseInt(arr[2]);
        int limit = Math.min(A, B);
        List<Integer> list = new ArrayList<>();
        for (int i = limit; i > 0; i--) {
            if (A % i == 0 && B % i == 0) {
                list.add(i);
            }
        }
        out.println(list.get(K - 1));
        out.close();
    }
}
