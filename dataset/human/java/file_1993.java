import java.util.*;

public class Main{
    void solve(){
        Scanner scan = new Scanner(System.in);
        long n = scan.nextLong();
        if(n == 1){
            System.out.println(0);
            return;
        }
        int out = 0;
        for(long i = 2; i <= Math.sqrt(n); i++){
            int e = 0;
            while(n % i == 0){
                n /= i;
                e++;
            }
            out += (Math.sqrt(8 * e + 1) - 1) / 2;
        }
        if(n > 1) out++;
        System.out.println(out);
    }

    public static void main(String[] args){
        new Main().solve();
    }
}
