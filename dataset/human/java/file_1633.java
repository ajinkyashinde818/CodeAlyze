import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        int N;
        String S;
        long MOD_NUM = 1000_000_007;
        List<Long> list = new ArrayList<>();
        try (Scanner sc = new Scanner(System.in)) {
            N = sc.nextInt();
            S = sc.next();
        }

        char[] chS = S.toCharArray();
        Set<Character> set = new HashSet<>(24);
        Map<Character, Integer> map = new HashMap<>(24);
        for (Character c : chS) {
            set.add(c);
            Integer v = map.getOrDefault(c, 0);
            map.put(c, ++v);
        }

        int typeNum = set.size();
        int[] arr = new int[typeNum];
        int index = 0;
        for (Map.Entry<Character, Integer> entry :map.entrySet()) {
            int value = entry.getValue();
            arr[index] = value +1;
            index++;
        }
        long result = 1;
        for (int i = 0; i < arr.length; i++) {
            result *= arr[i];
            result = result % MOD_NUM;

        }
        System.out.println(result-1);
    }


}
