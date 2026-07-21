import java.util.*;

public class Main {

    static final int MOD = 1000000007;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        char s[] = sc.next().toCharArray();
        Arrays.sort(s);
        System.out.println(s[0]=='a'&&s[1]=='b'&&s[2]=='c'?"Yes":"No");
    }
}
