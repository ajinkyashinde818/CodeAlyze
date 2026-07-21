import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        int N = S.length();

        int i = 0;
        while (i <= N - 1) {
            if (i + 6 <= N && S.substring(i, i + 6).equals("eraser")) {
                i += 6;
                continue;
            }

            if (i + 5 <= N && S.substring(i, i + 5).equals("erase")) {
                i += 5;
                continue;
            }

            if (i + 5 <= N && !S.substring(i, i + 5).equals("dream")) {
                System.out.println("NO");
                return;
            }

            if (i + 7 <= N && S.substring(i, i + 7).equals("dreamer")) {
                if (i + 8 <= N && S.substring(i, i + 8).equals("dreamera")) {
                    // dream
                    i += 5;
                    continue;
                }

                // dreamer
                i += 7;
                continue;
            }

            if (i + 5 <= N && S.substring(i, i + 5).equals("dream")) {
                i += 5;
                continue;
            }

            System.out.println("NO");
            return;
        }

        System.out.println("YES");
    }
}
