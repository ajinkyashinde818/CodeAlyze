import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static long lcm(long a, long b){
        long m = a;
		long n = b;   
        long t = m % n;
        while(t != 0){
            m = n;
            n = t;
            t = m % n;
        }                   
        long l = a * b / n;
        return l;
    }
    
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        String[]z=br.readLine().split(" ");
        long a = Integer.parseInt(z[0]);
        long b = Integer.parseInt(z[1]);
        long s = lcm(a , b);
        System.out.print(s);
    }
}
