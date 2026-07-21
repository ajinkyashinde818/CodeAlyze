import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String args[]) throws Exception{
        BufferedReader stdR = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(stdR.readLine());
        String[] str = stdR.readLine().split(" ");
        int[] A = new int[N];
        for(int i = 0 ; i < N ; i++) {
            A[i] = Integer.parseInt(str[i]);
        }
        int minuscount = 0;
        for(int i = 0 ; i < N ; i++) {
            if(A[i] < 0)minuscount++;
            A[i] = Math.abs(A[i]);
        }
        Arrays.sort(A);
        long l = 0;
        if(minuscount % 2 == 1) {
            l -= A[0];
            for(int i = 1 ; i < N ; i++) {
                l += (long)Math.abs(A[i]);
            }
        }else {
            for(int i = 0 ; i < N ; i++) {
                l += (long)Math.abs(A[i]);
            }
        }
        System.out.println(l);
    }
}
