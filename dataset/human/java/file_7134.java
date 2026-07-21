import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question question = new Question();
        question.solve(sc);
    }

    static class Question {
        public void solve(Scanner sc) {
            int len = sc.nextInt();
            int n = sc.nextInt();
            int[] distances = new int[n];
            for (int i = 0; i < n; ++i) {
                distances[i] = sc.nextInt();
            }
            int m = 0;
            for (int i = 0; i < n; ++i) {
                int t = (i + 1) % n;
                int dist = distances[t] - distances[i];
                m = Math.max(m, Math.min(Math.abs(dist), len - Math.abs(dist)));
            }
            System.out.println(len - m);
        }
    }
}
