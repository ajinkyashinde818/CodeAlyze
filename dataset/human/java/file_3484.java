import java.util.Scanner;

/**
 *
 * @author kke2
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String hex = sc.next();
        String fex = sc.next();
        int dec = Integer.parseInt(hex, 16);
        int inc = Integer.parseInt(fex, 16);
        if (dec < inc) {
            System.out.println("<");
        }
        if (inc < dec) {
            System.out.println(">");
        }
        if (inc == dec) {
            System.out.println("=");
        }

        // TODO code application logic here
    }

}
