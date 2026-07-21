import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        String s = sc.next();
        StringBuilder sb = new StringBuilder();
        sb.append(s);
        sb.reverse();
        s = sb.toString();
//        char[] s = sc.next().toCharArray();

        String[] arr = {"maerd", "remaerd", "esare", "resare"};

//        System.out.println(s);

        int idx = 0;

        out:
        while (idx < s.length()) {
            int cnt = 0;
            for (int i=0; i<4; i++) {
                if (s.substring(idx, Math.min(idx+8, s.length())).startsWith(arr[i])) {
                    idx += arr[i].length();
//                    s = s.replace(arr[i], "");
//                    System.out.println(s);
                    continue out;
                }
                cnt++;
            }
            if (cnt == 4) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");


    }

}
