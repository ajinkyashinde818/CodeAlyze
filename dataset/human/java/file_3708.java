import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String X = scan.next();
        String Y = scan.next();
        int a = Integer.parseInt(X, 16);
        int b = Integer.parseInt(Y, 16);
        if (a==b) {
            System.out.println("=");
        } else {
            System.out.println(a<b? "<" : ">");
        }
    }
}
