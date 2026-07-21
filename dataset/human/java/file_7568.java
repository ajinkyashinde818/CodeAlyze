import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String[] test = {"dreamer", "dream", "eraser", "erase"};
        boolean isAns = true;

        int index = s.length();
        while (index > 0) {
            boolean isCheck = false;
            for (int i = 0; i < 4; i++) {
                int start = Math.max(index-test[i].length(), 0);
                String sub = s.substring(start, index);
                if (sub.equals(test[i])) {
                    isCheck = true;
                    index = start;
                    break;
                }
            }

            if (!isCheck) {
                isAns = false;
                break;
            }
        }

        System.out.println(isAns ? "YES" : "NO");
    }
}
