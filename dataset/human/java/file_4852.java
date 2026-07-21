import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if (n%2==1){
            System.out.println(0);
        }else {
            long ans = 0;
            n/=10;
            ans+=n;
            while (n!=0){
                n/=5;
                ans+=n;
            }
            System.out.println(ans);
        }
    }
}
