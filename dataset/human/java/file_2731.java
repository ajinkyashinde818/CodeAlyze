import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = 0, j = 0;

        String message = sc.next();
        String re_message = sc.next();
        char[] chmessage = message.toCharArray();
        char[] chre_message = re_message.toCharArray();
        char temp[];
        temp = new char[chre_message.length];

        Arrays.sort(chmessage);
        Arrays.sort(chre_message);
        for (i = 0; chre_message.length > i; i++) {
            temp[chre_message.length - i - 1] = chre_message[i];
        }
        String str1 = String.valueOf(chmessage);
        String str2 = String.valueOf(temp);
        if (str1.compareTo(str2) < 0) {
            System.out.println("Yes");
        }
        if (str1.compareTo(str2) >= 0) {
            System.out.println("No");
        }

    }

}
