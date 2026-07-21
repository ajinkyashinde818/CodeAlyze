import java.util.*;

public class Main {
        public static void main(String args[]) {
                Scanner sc = new Scanner(System.in);
                String s = sc.nextLine();
                String t = sc.nextLine();
                char[] s2 = s.toCharArray();
                char[] t2 = t.toCharArray();

                Arrays.sort(s2);
                Arrays.sort(t2);
                for (int i = 0;;i++) {
                        if (i == t.length()) {
                                System.out.println("No");
                                break;
                        }
                        if (i == s.length()) {
                                System.out.println("Yes");
                                break;
                        }
                        if (s2[i] < t2[t.length() - i - 1]) {
                                System.out.println("Yes");
                                break;
                        } else if (s2[i] > t2[t.length() - i - 1]) {
                                System.out.println("No");
                                break;
                        }
                }
        }
}
