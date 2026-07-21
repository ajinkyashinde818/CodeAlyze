import java.util.*;

public class Main{

    private static int n;
    private static int m;
    private static int x;
    private static PriorityQueue<Integer> q;
    private static int[][] a;
    private static int[] c;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        x = sc.nextInt();

        c = new int[n];
        a = new int[n][m];

        for(int i = 0; i < n; i++){
            c[i] = sc.nextInt();
            for(int j = 0; j < m; j++){
                a[i][j]= sc.nextInt();
            }
        }

        q = new PriorityQueue<>();
        int[] sum = new int[m + 1];
        check(0, sum);
        Integer ans = q.poll();
        System.out.println(ans != null ? ans : -1);

    }

    static void check(int num, int[] sum){
        //System.out.print(num);
        check2(sum);
        if(num == n){
            return;
        }
        check(num + 1, sum);
        for(int i = 0; i < m; i++){
            sum[i] += a[num][i];
        }
        sum[m] += c[num];
        check(num + 1, sum);
        for(int i = 0; i < m; i++){
            sum[i] -= a[num][i];
        }
        sum[m] -= c[num];
    }

    static void check2(int[] sum){
        //System.out.println(Arrays.toString(sum));
        for(int i = 0; i < m; i++){
            if(sum[i] < x){
                return;
            }
        }
        q.add(sum[m]);
    }
}
