import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long first = scanner.nextLong();
        long second = scanner.nextLong();

        if (first > second) {
            foundLeastCommonMultiple(first, second);
        } else {
            foundLeastCommonMultiple(second, first);
        }
    }

    private static void foundLeastCommonMultiple(long bigger, long lesser) {
        boolean isFound = false;
        int biggerMultiplier = 1;
        int lesserMultiplier = 1;
        while (!isFound) {
            long biggerSum = bigger * biggerMultiplier;
            long lesserSum = lesser * lesserMultiplier;
            if (biggerSum == lesserSum) {
                System.out.println(biggerSum);
                isFound = true;
            } else if (biggerSum > lesserSum) {
                lesserMultiplier++;
            } else {
                biggerMultiplier++;
            }
        }
    }
}
