import java.awt.print.Printable;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);


        int n = Integer.parseInt(scan.next());
        int rate = Integer.parseInt(scan.next());
        //int c = Integer.parseInt(scan.next());
        if(n>=10)  {
            out.print(rate);
        } else {
            out.print(rate+(100 * (10 - n)));
        }


        out.flush();
    }
}
