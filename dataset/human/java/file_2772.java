import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String t = sc.next();

        char[] cs = new char[s.length() + 1];
        for (int i=0; i<s.length(); i++) {
            cs[i] = s.charAt(i);
        }
        cs[s.length()] = 200;
        Arrays.sort(cs);
        cs[s.length()] = 0;

        char[] ts = new char[t.length() + 1];
        for (int i=0; i<t.length(); i++) {
            ts[i] = t.charAt(i);
        }
        Arrays.sort(ts);

        for (int i=0; i<s.length() + 1; i++) {
            if (cs[i] < ts[t.length() - i]) {
                System.out.println("Yes");
                return;
            } else if (cs[i] == ts[t.length() -i]) {
                continue;
            } else {
                System.out.println("No");
                return;
            }
        }
        System.out.println("No");
    }
}
