import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ", 3);
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        int s = Integer.parseInt(line[2]);
        int another;
        if (s == 1000000000) {
            another = 1;
        } else {
            another = 1000000000;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                sb.append(" ");
            }
            if (i < k) {
                sb.append(s);
            } else {
                sb.append(another);
            }
        }
        System.out.println(sb);
    }
}
