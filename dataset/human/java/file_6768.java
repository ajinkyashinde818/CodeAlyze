import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    private static int MOD = 1000000007;


    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String str = br.readLine();
        String[] split = str.split(" ");
        int k = Integer.parseInt(split[0]);
        String[] s = br.readLine().split(" ");


        int maxDistance = 0;
        for (int i = 0; i < s.length - 1; i++) {
            int distance = Math.abs(Integer.parseInt(s[i]) - Integer.parseInt(s[i + 1]));
            if (maxDistance < distance) {
                maxDistance = distance;
            }
        }
        int distance = Math.abs(Integer.parseInt(s[s.length - 1]) - (k + Integer.parseInt(s[0])));
        if (maxDistance < distance) {
            maxDistance = distance;
        }

        System.out.println(k - maxDistance);
    }

}
