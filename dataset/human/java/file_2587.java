import java.util.*;

class Main {
    public static void main(String[] args) {
        new Solver().run();
    }
}

class Solver {

    private String minimize(String s) {
        String buf = new String(s);
        char[] a = buf.toString().toCharArray();
        Arrays.sort(a);
        return new String(a);
    }

    private String maximize(String s) {
        String buf1 = new String(s);
        char[] a = buf1.toString().toCharArray();
        Arrays.sort(a);
        return new StringBuilder(new String(a)).reverse().toString();
    }

    public void run() {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();

        String sd = minimize(s);
        String td = maximize(t);

        int ret = sd.compareTo(td);
        if (ret < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        return;
    }

}
