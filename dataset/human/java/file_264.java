import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) {
        try (CustomReader in = new CustomReader()) {
            new Main().execute(in);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void execute(CustomReader in) throws IOException {
        int N = Integer.parseInt(in.readLine());
        long[] A = in.readLineAsLongArray();
        long total = 0L;
        boolean containsZero = false;
        long minAbs = Long.MAX_VALUE;
        int negativeCnt = 0;
        for (int i = 0; i < N; i++) {
            total += Math.abs(A[i]);
            minAbs = Math.min(minAbs, Math.abs(A[i]));
            if (A[i] == 0) {
                containsZero = true;
            }
            if (A[i] < 0) {
                negativeCnt++;
            }
        }
        if (!containsZero && negativeCnt % 2 == 1) {
            total -= 2 * minAbs;
        }
        System.out.println(total);
    }


    static class CustomReader extends BufferedReader {
        public CustomReader() throws IOException {
            super(new InputStreamReader(System.in));
        }


        public int[] readLineAsIntArray() throws IOException {
            String[] strArray = this.readLine().split(" ");
            int[] intArray = new int[strArray.length];
            for (int i = 0, n = strArray.length; i < n; i++) {
                intArray[i] = Integer.parseInt(strArray[i]);
            }
            return intArray;
        }

        public long[] readLineAsLongArray() throws IOException {
            String[] strArray = this.readLine().split(" ");
            long[] longArray = new long[strArray.length];
            for (int i = 0, n = strArray.length; i < n; i++) {
                longArray[i] = Long.parseLong(strArray[i]);
            }
            return longArray;
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
    }

}
