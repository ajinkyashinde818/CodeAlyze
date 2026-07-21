import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int k = scanner.nextInt();
        int n = scanner.nextInt();
        List<Integer> locations = new ArrayList<>();

        int maxDiff = 0;
        int beforeLocation = 0;
        int totalDistance = 0;
        int firstLocation = 0;
        int lastLocation = 0;
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            locations.add(a);
            if (i == 0) {
                firstLocation = a;
            } else if (i == (n - 1)) {
                lastLocation = a;
            }

            totalDistance += a;
            int diff = a - beforeLocation;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
            beforeLocation = a;
        }

//        if (firstLocation > maxDiff || (k - lastLocation) > maxDiff) {
        if (((k - lastLocation) + firstLocation) > maxDiff) {
            System.out.println(lastLocation - firstLocation);
        } else {
            System.out.println(k - maxDiff);
        }
    }
}
