import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int x = scan.nextInt();
        System.out.println(x < 1200 ? "ABC" : "ARC");
    }
}
