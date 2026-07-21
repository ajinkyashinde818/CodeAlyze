import java.util.Scanner;

/**
 *
 * @author psygn
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        String str = scanner.nextLine();
        StringBuilder sb = new StringBuilder(str);
        String rev = sb.reverse().toString();
        String ans = "NO";
        int i = 0;
        while (true) {
            if (i == rev.length()) {
                ans = "YES";
                break;
            }
            try {
                if ("esare".equals(rev.substring(i, i+5))) {
                    i += 5;
                } else if ("maerd".equals(rev.substring(i, i+5))) {
                    i += 5;
                }  else if ("resare".equals(rev.substring(i, i+6))) {
                    i += 6;
                } else if ("remaerd".equals(rev.substring(i, i+7))) {
                    i += 7;
                } else {
                    break;
                }
            } catch (Exception e) {
                break;
            }
        }
        System.out.println(ans);
    }
}
