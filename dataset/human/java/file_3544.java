import java.util.Map;
import java.util.Scanner;

public class Main {

    /**
     * 本処理を実行します。
     */
    public static void execute() {
        Scanner sc = new Scanner(System.in);

        int x = Integer.parseInt(sc.next(), 16);
        int y = Integer.parseInt(sc.next(), 16);

        String res;
        if (x > y) {
            res = ">";
        } else if (x < y) {
            res = "<";
        } else {
            res = "=";
        }

        out(res);
    }

    /**
     * 次の標準入力をintで受け取ります。
     * @return 標準入力値(int)
     */
    public static int nextInt(Scanner sc) {
        return sc.nextInt();
    }

    /**
     * 次の標準入力をStringで受け取ります。
     * @return 標準入力値(String)
     */
    public static String nextString(Scanner sc) {
        return sc.next();
    }

    /**
     * 次の標準入力を指定回数分intで受け取ります。
     * @param n 取得回数
     * @return 取得した標準入力値の配列(int)
     */
    public static int[] nextInts(Scanner sc, int n) {
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = nextInt(sc);
        }

        return arr;
    }

    /**
     * 標準出力にオブジェクトを出力します。
     * @param o 出力対象
     */
    public static void out(Object o) {
        System.out.println(o);
    }

    public static void main(String[] args) {
        execute();
    }

    public static void putCountMap(Map<Integer, Integer> map, int value) {
        if (map.containsKey(value)) {
            map.put(value, map.get(value) + 1);
        } else {
            map.put(value, 1);
        }
    }
}
