import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int S = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        if (S!=1000000000) {
            for (int i=0;i<K;i++) {
                sb.append(String.valueOf(S));
                if (i!=N-1) sb.append(" ");
            }
            for (int i=0;i<N-K;i++) {
                sb.append(String.valueOf(S+1));
                if (i!=N-K-1) sb.append(" ");
            }
        } else {
            for (int i=0;i<K;i++) {
                sb.append(String.valueOf(S));
                if (i!=N-1) sb.append(" ");
            }
            for (int i=0;i<N-K;i++) {
                sb.append(String.valueOf(1));
                if (i!=N-K-1) sb.append(" ");
            }
        }
        System.out.println(sb);
    }
}
