import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n%2 == 1) {
            System.out.println(0);    
        }else {
            long ans = n/10;
            for(int i = 1; i<=36; i++) {
                long power = (long)Math.pow(5,i);
                if(power> (long)Math.pow(10,18)) break;
                ans += n/(10L*power);
            }
            System.out.println(ans);
        }
    }
}
