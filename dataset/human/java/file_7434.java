import java.util.*;

class Main {

    private static boolean startWith(char[] chars, String str, int offset) {
        char[] strChars = str.toCharArray();
        if (offset + str.length() > chars.length) {
            return false;
        }
        for (int i = 0; i < strChars.length; i++) {
            if (chars[i + offset] != strChars[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] tmp = sc.next().toCharArray();
        char[] T = new char[tmp.length];
        for (int i = 0; i < tmp.length; i++) {
            T[i] = tmp[tmp.length - 1 - i];
        }

        String[] words = new String[] {
                "maerd",
                "remaerd",
                "esare",
                "resare",
        };

        int offset = 0;
        while (true) {
            boolean notFound = true;
            for (int i = 0; i < words.length; i++) {
                if (startWith(T, words[i], offset)) {
                    notFound = false;
                    for (int j = offset; j < offset + words[i].length(); j++) {
                        T[j] = '.';
                    }
                    offset += words[i].length();
                }
            }
            if (notFound) {
                break;
            }
        }

        for (int i = 0; i < T.length; i++) {
            if (T[i] != '.') {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
