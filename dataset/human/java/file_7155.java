import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] num = new int[N];
        int[] dis = new int[N];
        num[0] = sc.nextInt();
        for(int i = 1; i < N; i++) {
            num[i] = sc.nextInt();
            dis[i-1] = num[i] - num[i-1];
        }
        dis[N-1] = K + num[0] - num[N-1];
        
        int max = 0;
        for(int i = 0; i < N; i++) {
            if(max < dis[i]){
                max = dis[i];
            }
        }
        System.out.println(K - max);
    }
}
