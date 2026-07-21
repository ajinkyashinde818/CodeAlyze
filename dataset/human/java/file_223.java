import java.util.Scanner;

class Solver {
    void solve(Scanner sc) {
        int N = sc.nextInt();

        long sum = 0;
        int first = sc.nextInt();
        boolean positive = first >= 0;
        int min = positive ? first : -first;
        for (int i = 1; i < N; i++) {
            int next = sc.nextInt();
            int abs;
            if (next < 0){
                abs = -next;
                positive ^= true;
            } else {
                abs = next;
            }

            if (min > abs){
                sum += min;
                min = abs;
            } else {
                sum += abs;
            }
        }
        if (positive){
            sum += min;
        } else {
            sum -= min;
        }

        System.out.println(sum);
    }
}

class Main {
    public static void main(String... args) {
        Scanner in = new Scanner(System.in);

        new Solver().solve(in);

        in.close();
    }
}
