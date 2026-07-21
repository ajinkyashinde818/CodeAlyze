import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String inputString = in.next();
        System.out.println(inputString.substring(0, inputString.length() - 8));
    }
}
