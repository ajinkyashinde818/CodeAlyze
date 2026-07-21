import java.util.Scanner;

public class Main implements Runnable {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new Thread(null, new Main(), "", 128 * 1024 * 1024).start();
    }

    public int goal;
    public int[][] arr;

    public void run() {
        int n = sc.nextInt() /* <= 10 */;
        goal = sc.nextInt();
        arr = new int[n][5];
        for (int i = 0; i < n; i++) {
            arr[i][0] = (i + 1) * 100; // for which score problem
            arr[i][1] = sc.nextInt(); // how many
            arr[i][2] = sc.nextInt(); // bonus
            arr[i][3] = arr[i][0] * arr[i][1] + arr[i][2]; // total
        }

        boolean[] left = new boolean[n];
        for (int i = 0; i < n; i++) {
            left[i] = true;
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int count = 0;
            int score = 0;
            min = Math.min(rec(count, score, left, i), min);
        }
        System.out.println(min);
    }

    public int rec(int count, int score, boolean[] left, int idx) {
        if (score >= goal) {
            return count;
        }

        for (int i = 0; i < arr[idx][1]; i++) {
            score += arr[idx][0];
            count++;
            if (score >= goal) {
                return count;
            }
        }
        score += arr[idx][2];
        if (score >= goal) {
            return count;
        }

        int min = Integer.MAX_VALUE;
        left[idx] = false;
        for (int i = 0; i < left.length; i++) {
            if (left[i]) {
                min = Math.min(rec(count, score, left, i), min);
            }
        }
        left[idx] = true;
        return min;
    }
}
