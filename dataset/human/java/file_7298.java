import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner std = new Scanner(System.in);
        String s = std.next();
        String reversed = new StringBuilder(s).reverse().toString();

        String[] texts = {"dream", "dreamer", "erase", "eraser"};
        String[] reversedText = new String[texts.length];
        for (int i = 0; i < texts.length; i++) {
            reversedText[i] = new StringBuilder(texts[i]).reverse().toString();
        }

        StringBuilder sb = new StringBuilder(reversed);
        while (sb.length() != 0) {
            boolean updated = false;
            for (int i = 0; i < reversedText.length; i++) {
                String r = reversedText[i];
                if (sb.indexOf(r) == 0) {
                    sb.delete(0, r.length());
                    updated = true;
                    break;
                }
            }

            if (!updated) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }
}
