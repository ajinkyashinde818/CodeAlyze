import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {

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
        String arr02[] = mylist.get(1).split(" ");
        String arr03[] = mylist.get(2).split(" ");
        String arr04[] = mylist.get(3).split(" ");

        String s = arr01[0];
        Integer n = Integer.valueOf(s);

        int mysum = 0;
        for (String v : arr03) {
            mysum += Integer.valueOf(v);

        }

        for (int i = 0; i < n - 1; i++) {

            int temp = Integer.valueOf(arr02[i]);

            if (temp + 1 == Integer.valueOf(arr02[i + 1])) {
                mysum += Integer.valueOf(arr04[temp - 1]);
            }

        }

        System.out.println(mysum);
    }

}
