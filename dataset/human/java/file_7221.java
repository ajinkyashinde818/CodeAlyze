import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] houses = new int[n];
        int prev = sc.nextInt();
        houses[0] = prev;
        int max = 0;
        int sum = 0;
        for (int i = 1; i < n; i++) {
            int place = sc.nextInt();
            int gap = place - prev;
            max = Integer.max(max, gap);
            prev = place;
            sum += gap;
            houses[i] = place;
        }
        int gap = houses[0] + k - houses[n-1];
        max = Integer.max(max, gap);
        sum += gap;
        sum -= max;
        System.out.println(sum);
    }
}
