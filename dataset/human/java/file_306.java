import java.util.*;
import java.lang.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
            int N = sc.nextInt();
            long[] S = new long[N];

            int minus = 0;

            for(int i = 0 ; i < N ; i++){
                S[i] = sc.nextLong();
                if(S[i] < 0){
                    minus++;
                    S[i] = Math.abs(S[i]);
                }
            }
        sc.close();

        Arrays.sort(S);

        long ans = 0 ;
        for (int i = 0 ; i < N ; i++){
                ans += Math.abs(S[i]);
        }

        if(minus%2 == 0){
            System.out.println(ans);
        }else{
            System.out.println(ans-Math.abs(S[0])-Math.abs(S[0]));
        }
        
    }
}
