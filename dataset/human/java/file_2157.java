import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        int threshold = (int) Math.sqrt(N) + 100; // 値の平方数超過の範囲には素数は多くても1つ / doubleの誤差調整
        List<Integer> primeNumbers = new ArrayList<>();

        int devideNum = 2;
        while(N % devideNum == 0) {
            primeNumbers.add(devideNum);
            N /= 2;
        }

        devideNum++;
        while (devideNum <= threshold) {
            if (N % devideNum == 0) {
                primeNumbers.add(devideNum);
                N /= devideNum;
            } else {
                devideNum +=2; // 2以外に偶数の素数は存在しない
            }
        }

        if(N != 1) {
            primeNumbers.add((int)N);
        }

        int e = 1;
        int result = 0;
        int last = 0;

        main: for(int i=0; i<primeNumbers.size(); i++) {
            int current = primeNumbers.get(i);

            if(current == last) {
                e++;
            }else {
                e = 1;
            }
            last = current;

            for(int j=2; j<=e; j++) {
                if(i+j-1 >= primeNumbers.size()) {
                    continue main;
                }
                if(primeNumbers.get(i+j-1) != current) {
                    continue main;
                }
            }
            result++;
            i = i+e-1;
        }

        System.out.println(result);

    }
}
