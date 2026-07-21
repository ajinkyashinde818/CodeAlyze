import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int i = 1;
        List<Integer> integers = new ArrayList<>();

        while (i <= a || i <= b) {
            if (a % i == 0 && b % i == 0) {
                integers.add(i);
            }
            i++;
        }
        System.out.println(integers.get(integers.size() - k));
    }
}
