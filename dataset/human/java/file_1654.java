import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        String s = sc.next();
        int[] c = new int[26];
        for(int i = 0; i < N; i++){
            int diff = s.charAt(i) - 'a';
            c[diff]++;
        }

        int mod = (int)Math.pow(10, 9)+7;
        long sum = 1;
        for(int i = 0; i < 26; i++){
            if(c[i] != 0)
                sum = (sum*(c[i]+1)%mod);
        }

        System.out.println(sum-1);
    }
}
