import java.io.*;
import java.math.*;
import java.util.*;


public class Main	 {
	public static HashMap<Long,Integer> factorize(long n) { 
		HashMap<Long,Integer> map = new HashMap<Long, Integer>();
        int count = 0; 
  
        // count the number of times 2 divides  
        while (!(n % 2 > 0)) { 
            // equivalent to n=n/2;  
            n >>= 1; 
  
            count++; 
        } 
  
        // if 2 divides it  
        if (count > 0) { 
        	map.put((long)2, count);
//            System.out.println("2" + " " + count); 
        } 
  
        // check for all the possible  
        // numbers that can divide it  
        for (long i = 3; i <= (long) Math.sqrt(n); i += 2) { 
            count = 0; 
            while (n % i == 0) { 
                count++; 
                n = n / i; 
            } 
            if (count > 0) { 
            	map.put(i, count);
//                System.out.println(i + " " + count); 
            } 
        } 
  
        // if n at the end is a prime number.  
        if (n > 2) { 
        	map.put(n, 1);
//            System.out.println(n + " " + "1"); 
        } 
        return map;
    } 
    public static void main(String[] args) throws IOException {
        	Scanner sc = new Scanner(System.in);
        	long n  = sc.nextLong();
        	HashMap<Long,Integer> map = new HashMap<Long,Integer>();
        	map = factorize(n);
        	Set<Long> keySet = map.keySet();
        	int res=0;
            List<Long> listKeys = new ArrayList<Long>( keySet );
        	for(int i=0;i<map.size();i++) {
        		Long key = listKeys.get(i);
        		int a = map.get(key);
        		int count =0;
        		for(int j=1;a-j>=0;j++) {
        			a=a-j;
        			count++;
        		}
        		res+=count;
        	}
        	System.out.print(res);
    }
}
