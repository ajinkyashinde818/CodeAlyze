import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // 入力処理
        Scanner sc = new Scanner(System.in);
        
        String str = sc.nextLine();

        String[] words = {"eraser", "erase", "dreamer", "dream"};

        for (String word : words) {
            if (str.matches(".*" + word + ".*")) {
                str = str.replaceAll(word, "");
            }
        }

        if (str.length() == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
