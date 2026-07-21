import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;


public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        int K = scan.nextInt();
        int S = scan.nextInt();
        int next = S+1;
        if (S == 1000000000) {
            next = S - 1;
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < K; i++) {
            list.add(S);
        }
        for (int i = K; i < N; i++) {
            list.add(next);
        }
        System.out.println(list.stream().map(i -> i.toString()).collect(Collectors.joining(" ")));
        return;
    }
}
