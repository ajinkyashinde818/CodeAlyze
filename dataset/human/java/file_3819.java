import java.util.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        char[] s = scan.nextLine().toCharArray();
        List<Character> non_n = new ArrayList<>();
        for( char tmp : s) {
            if (tmp != 'x') {
                non_n.add(tmp);
            }
        }
        for (int i = 0; i < non_n.size(); i++) {
            if (!non_n.get(i).equals(non_n.get(non_n.size() - i - 1))) {
                System.out.println("-1");
                return;
            }
        }

        int count = 0;
        int tail = s.length - 1;
        for (int i = 0; i < tail;) {
            if(s[i] == s[tail]) {
                i++;
                tail--;
                continue;
            }
            count++;
            if(s[i] == 'x') {
                i++;
            } else  {
                tail--;
            }
        }
        System.out.println(count);
    }
}
