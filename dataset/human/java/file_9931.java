import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        String[][] input_multiArray;
        input_multiArray = new String[N][M+1];

        int[] sum_array;

        int total = 1200001;

        for(int i = 0; i < N; i++) {
            input_multiArray[i] = br.readLine().split(" ");
        }

        X:for(int i = 0; i < (1 << N); i++) {
            int tmp = 0;
            sum_array = new int[M];
            for(int j = 0; j < N; j++) {
                if((i>>j & 1) == 1) {
                    String[] target_array = input_multiArray[j];
                    tmp += Integer.parseInt(target_array[0]);
                    for(int k = 0; k < M; k++) {
                        sum_array[k] += Integer.parseInt(target_array[k+1]);
                    }
                }
            }

            for(int num : sum_array) {
                if(num < X) continue X;
            }

            if(total > tmp) total = tmp;
        }

        if(total == 1200001) {
            pw.println(-1);
        } else {
            pw.println(total);
        }

        br.close();
        pw.close();
    }
}
