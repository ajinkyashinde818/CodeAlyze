import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String input = scanner.nextLine();
        String[] numbers = input.split(" ");

        int numContest = Integer.parseInt(numbers[0]);
        int innerRating = Integer.parseInt(numbers[1]);
        if (numContest >= 10) {
            System.out.println(innerRating);
        } else {
            System.out.println(innerRating + 100 * (10 - numContest));
        }
    }

}
