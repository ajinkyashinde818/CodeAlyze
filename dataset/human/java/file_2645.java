import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        Arrays.sort(s);
        String sAsc = new String(s);

        // char[]を一度ソートしてからその文字列を反転させることで逆順の文字列をえる
        Arrays.sort(t);
        String tAsc = new String(t);
        String tDesc = new StringBuilder(tAsc).reverse().toString();

        System.out.println(sAsc.compareTo(tDesc)<0 ? "Yes" : "No");
    }
}
