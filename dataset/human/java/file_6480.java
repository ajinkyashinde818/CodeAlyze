import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int total = 0;
        for(int i = 0;i <= K;i++){
            for(int j = 0;j <= K;j++){
                    int last = S - i - j;
                    if(last >= 0 && last <= K) total++;
            }
        }
        System.out.println(total);
    }
}
