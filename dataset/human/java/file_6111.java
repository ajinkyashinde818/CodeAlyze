// "static void main" must be defined in a public class.
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int K = scan.nextInt();
        int S = scan.nextInt();
        int ans = 0;
        for(int i = 0; i <= K; i++){
            for(int j = 0; j <= K; j++){
                if(S-i-j <= K && S-i-j >= 0){
                    ans++;
                }else if(S-i-j <= 0){break;}
            }
        }
        System.out.println(ans);
    }
}
