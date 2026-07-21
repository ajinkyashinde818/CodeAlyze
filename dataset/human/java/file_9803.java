import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        int x = Integer.parseInt(sc.next());
        int[] c = new int[n];
        int[][] a = new int[n][m];
        for(int i = 0; i < n; i++){
            c[i] = Integer.parseInt(sc.next());
            for(int j = 0; j < m; j++){
                a[i][j] = Integer.parseInt(sc.next());
            }
        }
        
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < 1<<n; i++){
            int[] b = new int[m];
            int cost = 0;
            for(int j = 0; j < n; j++){
                if((i>>j & 1) != 0){
                    for(int k = 0; k < m; k++){
                        b[k] += a[j][k];
                    }
                    cost += c[j];
                }
            }
            boolean flag = true;
            for(int j = 0; j < m; j++){
                if(b[j] < x) flag = false;
            }
            if(flag){
                min = Math.min(cost, min);
            }
        }
        if(min != Integer.MAX_VALUE){
            System.out.println(min);
        }else{
            System.out.println(-1);
        }
    }
}
