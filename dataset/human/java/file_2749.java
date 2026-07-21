import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        String [] sArray = new String[s.length()];
        String [] tArray = new String[t.length()];
        for (int i = 0 ; i < s.length() ; i ++) {
            sArray[i] = String.valueOf(s.charAt(i));
        }
        for (int i = 0 ; i < t.length() ; i ++) {
            tArray[i] = String.valueOf(t.charAt(i));
        }
        Arrays.sort(sArray);
        Arrays.sort(tArray);

        String sDash = "";
        String tDash = "";
        for (int i = 0 ; i < sArray.length ; i++) {
            sDash += sArray[i];
        }
        for (int i = 0 ; i < tArray.length ; i++) {
            tDash += tArray[tArray.length - 1 - i];
        }
        if (sDash.compareTo(tDash) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }

}
