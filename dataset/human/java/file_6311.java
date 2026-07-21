import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int K = Integer.parseInt(sc.next());
        int S = Integer.parseInt(sc.next());
        
        int ans = 0;
        for(int i=0; i<=K; i++){
            for(int j=0; j<=K; j++){
                int z = S - i - j;
                if(0 <= z && z <= K){
                    ans++;
                }
            }
        }
        
        System.out.println(ans);
    }
}
