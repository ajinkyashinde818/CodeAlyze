import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        char[] sArray = sc.next().toCharArray();
        char[] tArray = sc.next().toCharArray();

        Arrays.sort(sArray);
        Arrays.sort(tArray);

        String sortS = new String(sArray);
        String sortT = new String(tArray);
        StringBuffer sb = new StringBuffer(sortT);
        sortT = sb.reverse().toString();

        System.out.println(sortS.compareTo(sortT) < 0? "Yes" : "No");
    }
}
