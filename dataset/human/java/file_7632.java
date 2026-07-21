import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long k = sc.nextLong();

        int[] a = new int[n + 1];
        int[] count = new int[n + 1];
        Arrays.fill(count, Integer.MAX_VALUE);

        for(int i = 1; i <= n; i++){
            a[i] = sc.nextInt();
        }

        int current = 1;
        int cnt = 0;

        while(count[current] == Integer.MAX_VALUE){
            count[current] = cnt;
            current = a[current];
            cnt++;
            k--;
            if(k == 0){
                System.out.println(current);
                return;
            }
        }

        Arrays.fill(count, Integer.MAX_VALUE);
        cnt = 0;

        while(count[current] == Integer.MAX_VALUE){
            count[current] = cnt;
            current = a[current];
            cnt++;
            k--;
            if(k == 0){
                System.out.println(current);
                return;
            }
        }

        k %= cnt;

        while(true){
            if(k == 0){
                System.out.println(current);
                return;
            }
            current = a[current];
            k--;
        }

    }

}
