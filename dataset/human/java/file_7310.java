import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        String ans = "YES";

        int index = s.length();

        while (index > 0) {
            boolean isOK = false;

            if (index >= 7 && s.substring(index - 7, index).equals("dreamer")) {
                isOK = true;
                index -= 7;
            }
            else if (index >= 5 && s.substring(index - 5, index).equals("dream")) {
                isOK = true;
                index -= 5;
            }
            else if (index >= 6 &&s.substring(index - 6, index).equals("eraser")) {
                isOK = true;
                index -= 6;
            }
            else if (index >= 5 && s.substring(index - 5, index).equals("erase")) {
                isOK = true;
                index -= 5;
            }

            if (!isOK) {
                ans = "NO";
                break;
            }
        }

        System.out.println(ans);
    }
}
