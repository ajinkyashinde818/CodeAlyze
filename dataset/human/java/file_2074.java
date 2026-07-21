import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public Main() {
        Scanner scanner = new Scanner(System.in);
        Long N = scanner.nextLong();

        HashMap<Long, Integer> HM = new HashMap();

        for (long i = 2; i*i <= N; i++) {
            if (N % i != 0) continue;

            int num = 0;
            while(N % i == 0){
                num++;
                N /= i;
            }
            HM.put(i, num);
        }

        if(N != 1){
            HM.put(N, 1);
        }

        long R = 0;
        for (Long key : HM.keySet()){
            int i = 1;
            while(true) {
                if (HM.get(key) >= i) {
                    R++;
                    HM.put(key, HM.get(key)-i);
                    i++;
                } else {
                    break;
                }
            }
        }

        System.out.println(R);
    }

    public static void main(String[] args) {
        new Main();
    }
}
