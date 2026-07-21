import javax.swing.*;
import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {


    public static void main(String[] args) {
        try (CustomReader in = new CustomReader()) {
            new Main().execute(in);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void execute(CustomReader in) throws IOException {
        int[] dg = in.readLineAsIntArray();
        final int D = dg[0];
        final int G = dg[1];
        int[] p = new int[D];
        int[] c = new int[D];
        int totalProblems = 0;
        for (int i = 0; i < D; i++) {
            int[] pc = in.readLineAsIntArray();
            p[i] = pc[0];
            c[i] = pc[1];
            totalProblems += p[i];
        }
        int ans = totalProblems;

        for (int i = 0, bound = 1 << D; i < bound; i++) {
            int score = 0;
            int cnt = 0;
            ArrayList<Integer> problems = new ArrayList<>();
            for (int j = 0; j < D; j++) {
                int mask = 1 << j;
                if ((i & mask) > 0) {
                    score += p[j] * 100 * (j + 1) + c[j];
                    cnt += p[j];
                } else {
                    for (int k = 0; k < p[j] - 1; k++) {
                        problems.add(100 * (j + 1));
                    }
                }

            }

            for (int k = problems.size() - 1; score < G && k >= 0; k--) {
                score += problems.get(k);
                cnt++;
            }
            if (score >= G) {
                ans = Math.min(ans, cnt);
            }
        }
        System.out.println(ans);
    }


    static class CustomReader extends BufferedReader {
        public CustomReader() throws IOException {
            super(new InputStreamReader(System.in));
        }

        public int readLineAsInt() throws IOException {
            return Integer.parseInt(readLine());
        }

        public int[] readLineAsIntArray() throws IOException {
            String[] strArray = this.readLine().split(" ");
            int[] intArray = new int[strArray.length];
            for (int i = 0, n = strArray.length; i < n; i++) {
                intArray[i] = Integer.parseInt(strArray[i]);
            }
            return intArray;
        }

        public int[][] readAsIntMatrix(int rows, int columns) throws IOException {
            int[][] matrix = new int[rows][columns];
            for (int i = 0; i < rows; i++) {
                String[] r = this.readLine().split(" ");
                for (int j = 0; j < columns; j++) {
                    matrix[i][j] = Integer.parseInt(r[j]);
                }
            }
            return matrix;
        }

        public char[][] readAsCharMatrix(int rows) throws IOException {
            char[][] matrix = new char[rows][];
            for (int i = 0; i < rows; i++) {
                matrix[i] = this.readLine().toCharArray();
            }
            return matrix;
        }

    }

}
