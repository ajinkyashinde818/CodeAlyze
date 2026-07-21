import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String input = scanner.next();
        int index = input.lastIndexOf("FESTIVAL");
        System.out.println(input.substring(0, index));
    }

}
