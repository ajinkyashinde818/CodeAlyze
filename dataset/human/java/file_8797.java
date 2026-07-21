import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int rank = sc.nextInt();

        int[] results = IntStream.rangeClosed(1, Math.min(num1, num2)).filter(i -> (num1 % i == 0))
                .filter(i -> (num2 % i == 0)).sorted().toArray();

        System.out.println(results[results.length - rank]);
    }
}
