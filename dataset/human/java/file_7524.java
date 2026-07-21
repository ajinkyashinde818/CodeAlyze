import java.util.Scanner;

public class Main {

    private static final String[] words = {"eraser", "erase", "dreamer", "dream"};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        for (int i = 0; i < words.length; i++) {
            s = s.replaceAll(words[i], "");
        }
        if (s.equals("")) {
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }

}
