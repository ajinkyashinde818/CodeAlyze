import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws Exception {

        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(is);

        List<String> mylist = new ArrayList<>();

        // 標準入力からの値を変数strinputに代入
        String strinput = reader.readLine();

        while (strinput != null) {

            mylist.add(strinput);
            strinput = reader.readLine();

        }

        String arr_temp[] = mylist.get(0).split(" ");

        int a = Integer.valueOf(arr_temp[0]);
        int b = Integer.valueOf(arr_temp[1]);

        //        System.out.println(a + " " + b);

        //        System.out.println(gcd(a, b));

        int ans = gcd(a, b);
        long temp = (long) a * (long) b;
        System.out.println(temp / ans);

    }

    public static int gcd(int a, int b) {

        // 引き数のint値を表示
        //        System.out.println(a + " " + b);

        // bがゼロならaを返却
        if (b == 0) {
            return a;
        }

        // そうじゃないなら再計算
        return gcd(b, a % b);
    }

}
