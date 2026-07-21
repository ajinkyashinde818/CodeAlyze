import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        List<String> list = new ArrayList<>();
        list.add("maerd");
        list.add("remaerd");
        list.add("esare");
        list.add("resare");

        StringBuilder sb = new StringBuilder(s);
        s = sb.reverse().toString();

        for (int i = 0; i < s.length(); ) {
            boolean flag = false;
            for (String str : list) {
                if (s.startsWith(str, i)) {
                    i += str.length();
                    flag = true;
                    break;
                }

            }
            if (!flag) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
