import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long ans = 0;
        for(long i = 2; i * i <= n; i++){
            int count = 0;
            while(n % i == 0){
                count++;
                n/=i;
            }
            for(int j = 1; count - j >= 0; j++){
                ans++;
                count -= j;
            }
        }
        if(n > 1){
            ans++;
        }
        System.out.println(ans);
    }
}
