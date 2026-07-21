import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        Arrays.sort(s);
        Arrays.sort(t);
        String ts = new StringBuilder(new String(t)).reverse().toString();
        System.out.println(new String(s).compareTo(ts) < 0 ? "Yes" : "No");
    }
}
