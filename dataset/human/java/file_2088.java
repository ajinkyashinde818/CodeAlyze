import java.util.*;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int res = 0;
        for(int i=2; i<=1000000; i++) {
            long div = i;
            while(n % div == 0 && div <= n) {
                n/=div;
                res++;
                div*=i;
            }
            while(n % i == 0) {
                n/=i;
            }
        }
        if(n != 1) res++;
        System.out.println(res);
    }




}
