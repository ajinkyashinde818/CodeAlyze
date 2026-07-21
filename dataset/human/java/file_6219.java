import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int S = sc.nextInt();
        int ans = 0;

        for(int i=0; i<=K; i++){
            int X = i;
            for(int j=0; j<=K; j++){
                int Y = j;
                if(S-X-Y>=0 && S-X-Y<=K){
                    ans += 1;
                }
            }
        }

        System.out.println(ans);
    }
}
