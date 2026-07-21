import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] d = new int[N][2];
        for(int n=0; n<N; n++){
            d[n][0] = sc.nextInt();
            d[n][1] = sc.nextInt();
        }

        for(int n=0; n<N-2; n++){
            if(d[n][0]==d[n][1] && d[n+1][0]==d[n+1][1] && d[n+2][0]==d[n+2][1]){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");        
    }
}
