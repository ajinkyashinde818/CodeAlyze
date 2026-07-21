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

        String arr01[] = mylist.get(0).split(" ");
        int a = Integer.valueOf(arr01[0]);
        int b = Integer.valueOf(arr01[1]);
        int c = Integer.valueOf(arr01[2]);

        int cnt = 0;

        //        System.out.println(a + " " + b + " " + c);

        if (c >= a) {
            cnt += a;
            c -= a;
            a = 0;
        } else {
            cnt += c;
            a -= c;
            c = 0;

        }

        //        System.out.println(a + " " + b + " " + c + " " + cnt);

        if (c >= b) {
            //cnt += c;
            cnt += b * 2;
            c -= b;
            b = 0;

            if (c > 0) {
                cnt += 1;
            }
            //            c = 0;
            //            b = 0;
        } else {
            cnt += b;
            cnt += c;
        }

        //        System.out.println(a + " " + b + " " + c + " " + cnt);
        System.out.println(cnt);

    }

}
