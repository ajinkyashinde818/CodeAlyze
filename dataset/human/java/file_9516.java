import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        int counter = 0;
        boolean ansFlag = false;

        for(int i = 0; i < N; i++) {
            String[] input_array = br.readLine().split(" ");
            if(input_array[0].equals(input_array[1])) {
                counter += 1;
            } else {
                counter = 0;
            }

            if(counter == 3) {
                ansFlag = true;
            }
        }

        if(ansFlag){
            pw.println("Yes");
        } else {
            pw.println("No");
        }

        br.close();
        pw.close();
    }
}
