import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int m = s.nextInt();

        int[] arr = new int[m];
        int prev1 = -1;
        for (int i = 0; i < m; i++) {
            int broken = s.nextInt();
            if (broken == prev1 + 1) {
                System.out.println(0);
                return;
            }
            arr[i] = prev1 = broken;
        }
        if (arr.length == 0) {
            ArrayList<BigInteger> fiboArr = new ArrayList<>(n * 2);
            fiboArr.add(BigInteger.valueOf(1));
            fiboArr.add(BigInteger.valueOf(1));
            fiboArr.add(BigInteger.valueOf(2));
            fiboArr.add(BigInteger.valueOf(3));
            fiboArr.add(BigInteger.valueOf(5));
            fiboArr.add(BigInteger.valueOf(8));
            fiboArr.add(BigInteger.valueOf(13));
            fiboArr.add(BigInteger.valueOf(21));
            fiboArr.add(BigInteger.valueOf(34));

            BigInteger aaa = BigInteger.valueOf(1000000007);
            BigInteger answer = fibo(fiboArr, n + 1);
            answer = answer.mod(aaa);

            System.out.println(answer.longValue());
            return;
        }

        int prev2;
        int[] renzoku = new int[m + 1];
        renzoku[0] = arr[0];
        int maxRen = arr[0];
        prev2 = arr[0];
        for (int i = 1; i < m; i++) {
            int next = arr[i];
            renzoku[i] = next - prev2 - 1;
            maxRen = Math.max(maxRen, renzoku[i]);
            prev2 = next;
        }
        renzoku[m] = n - prev2;
        maxRen = Math.max(maxRen, renzoku[m]);

        // 1: 1
        // 2: 1
        // 3: 2
        // 4: 3
        // 5: 5
        // 6: 8

        ArrayList<BigInteger> fiboArr = new ArrayList<>(maxRen * 2);
        fiboArr.add(BigInteger.valueOf(1));
        fiboArr.add(BigInteger.valueOf(1));
        fiboArr.add(BigInteger.valueOf(2));
        fiboArr.add(BigInteger.valueOf(3));
        fiboArr.add(BigInteger.valueOf(5));
        fiboArr.add(BigInteger.valueOf(8));
        fiboArr.add(BigInteger.valueOf(13));
        fiboArr.add(BigInteger.valueOf(21));
        fiboArr.add(BigInteger.valueOf(34));

        BigInteger answer = BigInteger.valueOf(1);
        BigInteger aaa = BigInteger.valueOf(1000000007);
        for (int i = 0; i < m + 1; i++) {
            answer = answer.multiply(fibo(fiboArr, renzoku[i]));
            answer = answer.mod(aaa);
        }

        System.out.println(answer.longValue());
    }

    private static BigInteger fibo(ArrayList<BigInteger> temp, int _i) {
        int i = _i - 1;
        if (temp.size() > i) {
            return temp.get(i);
        }
        int last = temp.size();

        for (int i1 = last; i1 <= i; i1++) {
            temp.add(temp.get(i1 - 2).add(temp.get(i1 - 1)));
        }
        return temp.get(i);
    }
}
