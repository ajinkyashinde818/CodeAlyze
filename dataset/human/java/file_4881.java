import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long ans = 0;
        if(N % 2 == 0){
            long k = 10;
            while(k <= N){
                ans += N / k;
                k *= 5;
            }
            
        }
        else{
            System.out.println("0");
            return;
        }
        System.out.println(ans);
    }
}
