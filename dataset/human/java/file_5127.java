import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder(br.readLine());
        boolean order = true;
        int q = Integer.parseInt(br.readLine());
        StringBuilder front = new StringBuilder();
        for (int i = 0; i < q; i++) {
            char[] arr = br.readLine().toCharArray();
            if (arr[0] == '1') {
                order ^= true;
            } else {
                int y = arr[2] - '0';
                if (order ^ y == 1) {
                    sb.append(arr[4]);
                } else {
                    front.append(arr[4]);
                }
            }
        }
        if (order) {
            front.reverse();
            System.out.println(front.toString() + sb.toString());
        } else {
            sb.reverse();
            System.out.println(sb.toString() + front.toString());
        }
    }
}
