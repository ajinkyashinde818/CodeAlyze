import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        final long A = Integer.parseInt(sc.next());
        final long B = Integer.parseInt(sc.next());
        long ans = 0;
        
        for (int i = 1; i <= B; i++) {
            if (A * i % B == 0) {
                ans = A * i;
                break;
            }
        }
        
        out.println(ans);
        
        out.flush();
    }
}
