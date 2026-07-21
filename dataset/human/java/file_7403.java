import java.util.*;

public class Main {
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        sc.close();

        ArrayList<String> word_list = new ArrayList(Arrays.asList("dream", "dreamer", "erase", "eraser"));
        char[] S_char_list = new StringBuilder(S).reverse().toString().toCharArray();

        int idx = 0;
        int tmp_idx = 0;

        boolean next_flg = true;
        while (idx < S_char_list.length) {
            for (String word : word_list) {
                tmp_idx = idx;
                next_flg = true;
                for (int i = word.length() - 1; i >= 0; i--, tmp_idx++) {
                    if (S_char_list[tmp_idx] != word.charAt(i)) {
                        next_flg = false;
                        break;
                    }
                }
                if (next_flg) {
                    idx += word.length();
                    break;
                }
            }
            if (!next_flg)
                break;
        }

        System.out.println(idx >= S_char_list.length ? "YES" : "NO");
    }
}
