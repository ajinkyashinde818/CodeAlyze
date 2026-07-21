import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    private static long findCity(long K, int[] arr) {
        int city = 1, count = 1;
        Map<Integer, Integer> map = new HashMap<>();

        while (K > 0 && !map.containsKey(city)) {
            map.put(city, count);
            city = arr[city];
            count++;
            K--;
        }

        if (K == 0) {
            return city;
        }

        K = K % (count - map.get(city));
        if (K < 0) {
            K += (count - map.get(city));
        }

        while (K > 0) {
            city = arr[city];
            K--;
        }

        return city;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        int[] arr = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(findCity(K, arr));
        sc.close();
    }
}
