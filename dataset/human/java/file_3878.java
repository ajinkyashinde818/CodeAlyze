import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        // 回文にできるか判定する
        String[] array = s.split("x+");
        StringBuilder builder = new StringBuilder();
        for (String v: array
             ) {
            builder.append(v);
        }
        String formatted = builder.toString();

        for (int i = 0; i < formatted.length() / 2; i++) {
            if (formatted.charAt(i) != formatted.charAt(formatted.length() - 1 - i)) {
                System.out.println(-1);
                return;
            }
        }

        builder = new StringBuilder(s);

        int index = 0;
        long ans = 0;
        while (index < builder.length() / 2) {
            boolean firstIsX = builder.charAt(index) == 'x';
            boolean endIsX = builder.charAt(builder.length() - 1 - index) == 'x';
            if (firstIsX && !endIsX) {
                builder.insert(builder.length() - index, "x");
                ans++;
            } else if (!firstIsX && endIsX) {
                builder.insert(index, "x");
                ans++;
            } else {
                index++;
            }
        }

        System.out.println(ans);
    }
}
