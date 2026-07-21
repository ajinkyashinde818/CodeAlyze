import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        int x = Integer.parseInt(sc.next());
        int[] c = new int[n];
        int[][] a = new int[n][m];
        for(int i=0; i<n; i++) {
            c[i] = Integer.parseInt(sc.next());
            for(int j=0; j<m; j++) {
                a[i][j] = Integer.parseInt(sc.next());
            }
        }
        
        
        int min = Integer.MAX_VALUE;
        for(int i=0; i<Math.pow(2, n); i++) {
            int[] asum = new int[m];
            int csum = 0;
            for(int j=0; j<n; j++) {
                if((1 & i >> j) == 1) {
                    csum += c[j];
                    for(int k=0; k<m; k++) {
                        asum[k] += a[j][k];
                    }
                }
            }
            
            boolean hantei = true;
            for(int k=0; k<m; k++) {
                if(asum[k] < x) {
                    hantei = false;
                    break;
                }
            }
            if(hantei) {
                if(min > csum) min = csum;
            }
        }
        
        if(min == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(min);
    }
}
