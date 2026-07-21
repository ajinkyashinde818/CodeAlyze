import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for(int i = 0; i < N; i++){
            A[i] = sc.nextInt();
        }
        int[] distance = new int[N];
        for(int i = 0; i < N-1; i++){
            distance[i] = A[i+1] - A[i];
        }
        distance[N-1] = K-A[N-1] + A[0];
        int all = 0;
        int min = Integer.MAX_VALUE;
        int count = 0;
        for(int i = 0; i < N; i++){
            all = all + distance[i];
        }
        for(int i = 0; i < N; i++){
            count = all - distance[i];
            if(min > count) min = count;
        }
        System.out.println(min);
    }
}
