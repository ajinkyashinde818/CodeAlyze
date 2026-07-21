import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        Arrays.sort(s);
        System.out.println(new String(s).equals("abc") ? "Yes" : "No");
    }
}
