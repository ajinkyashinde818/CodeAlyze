import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();
        char[] strArray = S.toCharArray();
        int[] countChar = new int[26];
        for(int i = 0; i < strArray.length; i++){
            countChar[((int)strArray[i]) % 26] ++;
        }
        
        BigInteger total = new BigInteger("1");
        for(int i = 0; i < 26; i++){
            total = total.multiply(new BigInteger(Integer.toString(countChar[i]+1)));
        }
        total = total.subtract(new BigInteger("1"));
        BigInteger ans = total.remainder(new BigInteger(Integer.toString(1000000007)));
        System.out.println(ans);
    }
}
