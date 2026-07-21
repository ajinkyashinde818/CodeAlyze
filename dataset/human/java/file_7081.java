import java.util.*;

public class Main {
    public static void main(String[] args) {
        //コード
        Scanner scanner = new Scanner(System.in);
        Integer K = Integer.parseInt(scanner.next());
        Integer N = Integer.parseInt(scanner.next());
        Integer[] dis = new Integer[N];
        Integer[] total = new Integer[N];

        for (int i = 0; i < N; i++) {
           dis[i] = Integer.parseInt(scanner.next());
        }
        for (int i = 0; i < N-1; i++) {
            total[i] = Math.abs(dis[i] - dis[i + 1]);
        }

        total[N-1] = Math.abs((K - dis[N-1]) + dis[0]);
        Arrays.sort(total);
        total[total.length-1] = 0;
        Integer sum = 0;
        for (int i = 0; i < total.length; i++) sum += total[i];
        System.out.println(sum);
    }
}
