import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws Exception{
		int num = 998244353;

		// TODO Auto-generated method stub
 		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
 		PrintWriter out = new PrintWriter(System.out);

 		
 		long n = Long.parseLong(bf.readLine());
 		Map<Long, Integer> pf = factorize(n);
 		long sum = 0;
 		for(long i : pf.keySet()){
 			int k = pf.get(i);
 			int t = (int)(Math.sqrt(2*k+0.25)-0.5);
 			sum+=t;
 		}
 		out.println(sum);
 		out.close();
 		
 	}
	
	public static Map<Long, Integer> factorize(long n) { 
	 	Map<Long, Integer> pf = new HashMap<Long, Integer>();
        int count = 0; 
        while (!(n % 2 > 0)) { 
            n >>= 1; 
            count++; 
        } 
        if (count > 0) { 
            pf.put((long)(2) , count);
        } 

        for (long i = 3; i <= (long) Math.sqrt(n); i += 2) { 
            count = 0; 
            while (n % i == 0) { 
                count++; 
                n = n / i; 
            } 
            if (count > 0) { 
                pf.put(i, count);
            } 
        } 
 
        if (n > 2) { 
           pf.put(n, 1);
        } 
        return pf;
    }

}
 	
 
//StringJoiner sj = new StringJoiner(" "); 
//sj.add(strings)
//sj.toString() gives string of those stuff w spaces or whatever that sequence is
