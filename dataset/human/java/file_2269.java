import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        int[] mins = new int[n];
        int[] maxs = new int[n];
        int[] minBucket = new int[n+1];
        int[] maxBucket = new int[n];
        
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            int sPos = str.indexOf(' ');
            mins[i] = Integer.parseInt(str.substring(0, sPos)) - 2;
            maxs[i] = Integer.parseInt(str.substring(sPos + 1)) - 2;
            
            minBucket[Math.min(mins[i], n)]++;
            maxBucket[Math.min(maxs[i], n-1)]++;
        }
        int maxmin = 0;
        int curPeep = 0;
        for (int i = n; i > 0; i--) {
            curPeep += maxBucket[i-1] - minBucket[i];
            if (i <= curPeep) {
                maxmin = i;
                break;
            }
        }
        
        System.out.println(maxmin);
        
    }

}
