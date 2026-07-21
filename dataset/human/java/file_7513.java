import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            String S = reader.readLine();
            int L = S.length();

            int a = 0;
            while (true) {
                if (L - a < 5) {
                    break;
                }

                String s = S.substring(a, a + 5);

                if (s.equals("dream")) {
                    a += 5;
                    if (L - a >= 2 && S.subSequence(a, a + 2).equals("er")) {
                        if (L - a < 3 || S.charAt(a + 2) != 'a') {
                            a += 2;
                        }
                    }
                } else if (s.equals("erase")) {
                    a += 5;
                    if (L - a >= 1 && S.charAt(a) == 'r') {
                        a += 1;
                    }
                } else {
                    break;
                }
            }

            if (a == L) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

}
