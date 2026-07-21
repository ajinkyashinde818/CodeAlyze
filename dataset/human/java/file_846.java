import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
//        sc.useDelimiter(",");
//        DecimalFormat df = new DecimalFormat("0.00000000");
        int n = Integer.parseInt(sc.next());
        int r = Integer.parseInt(sc.next());
        out.println(n >= 10 ? r : 100*(10-n)+r);

        out.flush();
    }
}
