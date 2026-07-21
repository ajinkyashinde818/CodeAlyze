import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int a[][] = new int[N][2];
        for(int i = 0; i < N; i++){
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
        }

        String ans = "No";

        for(int i = 0; i < N - 2; i++){
            if(a[i][0] == a[i][1] && a[i+1][0] == a[i+1][1] && a[i+2][0] == a[i+2][1]){
                ans = "Yes";
                break;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}
