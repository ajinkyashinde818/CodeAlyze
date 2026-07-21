import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n%2 == 1) {
            System.out.println(0);
            return;
        }
        n/=2;
        long res = 0;
        while(n>=5) {
            res += n/5;
            n/=5;
        }
        System.out.println(res);
    }


}
