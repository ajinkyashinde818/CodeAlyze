import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            // 標準入力
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            char sArr[] = makeCharArr(br.readLine());
            sArr = charSortAsc(sArr);
            char tArr[] = makeCharArr(br.readLine());
            tArr = charSortDesc(tArr);
            int length;
            if (sArr.length > tArr.length) {
                length = tArr.length;
            } else {
                length = sArr.length;
            }
            String ans = "";
            for (int i = 0; i < length; i++) {
                char s = sArr[i];
                char t = tArr[i];
                if (t > s) {
                    ans = "Yes";
                    break;
                } else if (s > t) {
                    ans = "No";
                    break;
                }
            }
            if ("".equals(ans)) {
                if (tArr.length > length) {
                    ans = "Yes";
                } else {
                    ans = "No";
                }
            }
            System.out.println(ans);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static char[] makeCharArr(String str) {
        char charArr[] = new char[str.length()];
        for (int i = 0; i < str.length(); i++) {
            charArr[i] = str.charAt(i);
        }
        return charArr;
    }

    public static char[] charSortAsc(char charArr[]) {
        for (int i = 0; i < charArr.length - 1; i++) {
            for (int j = i + 1; j < charArr.length; j++) {
                if (charArr[i] > charArr[j]) {
                    char tmp = charArr[i];
                    charArr[i] = charArr[j];
                    charArr[j] = tmp;
                }
            }
        }
        return charArr;
    }

    public static char[] charSortDesc(char charArr[]) {
        for (int i = 0; i < charArr.length - 1; i++) {
            for (int j = i + 1; j < charArr.length; j++) {
                if (charArr[i] < charArr[j]) {
                    char tmp = charArr[i];
                    charArr[i] = charArr[j];
                    charArr[j] = tmp;
                }
            }
        }
        return charArr;
    }
}
