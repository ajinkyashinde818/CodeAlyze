import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        long[] A = Stream.of(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        
        long sum = 0;
        int minusValueCount = 0;
        int absMin = (int) 1e9 + 1;
        
        for(int i = 0; i < N; i++){
            if( A[i] < 0 ) minusValueCount++;
            absMin = Math.min(absMin, (int)Math.abs(A[i]));
            sum += Math.abs(A[i]);
        }
        
        if( minusValueCount % 2 == 0){
            System.out.println(sum);
        } else {
            System.out.println(sum - absMin * 2);
        }
        
    }
}
