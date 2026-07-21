import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String X = sc.next();
        String Y = sc.next();

        String alphaHex = "ABCDEF";

        if (alphaHex.indexOf(X) < alphaHex.indexOf(Y)) {
            System.out.println("<");
        }else if (alphaHex.indexOf(X) == alphaHex.indexOf(Y)){
            System.out.println("=");
        }else{
            System.out.println(">");
        }
    }

}
