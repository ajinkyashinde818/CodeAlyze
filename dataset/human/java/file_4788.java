import java.awt.*;
import java.util.*;
import java.text.*;
import java.util.List;

public class Main {

    Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        new Main().run();
    }

    void run() {

        long n = sc.nextLong();
        long ans = 0;

        long five = 5;
        List<Long> list = new ArrayList<>();
        while (five <= n) {
            list.add(five);
            five *= 5;
        }
//        System.out.println(list);
        
        if (n % 2 == 1) {
            System.out.println(0);
            return;
        }

        for (long t: list) {
            ans += n / t / 2L;
        }

        System.out.println(ans);
    }


}
