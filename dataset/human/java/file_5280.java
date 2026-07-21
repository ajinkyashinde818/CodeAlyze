import java.util.*;

class Main {

    static int n;
    static char [][] field;
    static int [][] greatestSize;

    static void solve () {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (field[i][j] == '*') {
                    greatestSize[i][j] = 0;
                } else if ( i == 0 || j == 0 ) {
                    greatestSize[i][j] = 1;
                } else {
                    greatestSize[i][j] = Math.min(greatestSize[i-1][j-1], Math.min(greatestSize[i-1][j], greatestSize[i][j-1])) + 1;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result = Math.max(result, greatestSize[i][j]);
            }
        }

        System.out.println(result);
    }

    public static void main (String [] args) {

        Scanner sc = new Scanner(System.in);

        while(true) {
            n = sc.nextInt();

            if (n == 0) break;

            field = new char[n][n];
            greatestSize = new int [n][n];
            for (int i = 0; i < n; i++) {
                field[i] = sc.next().toCharArray();
                for(int j = 0; j < n; j++) {
                    greatestSize[i][j] = 0;
                }
            }
            
            solve();
        }

    }
}
