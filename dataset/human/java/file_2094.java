import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long N = Long.parseLong(st.nextToken());
        int[] primeFactors = new int[10000000];
        long n = N;
        for (long i=2; i*i<=n+2; i++){
            while(N%i==0){
                primeFactors[(int)i]++;
                N/=i;
            }
        }
        int ans=0;

        for (long i=2; i*i<=n+2; i++){
            int cur=primeFactors[(int)i];
            for (int k=1; k<=cur; k++){
                cur-=k;
                ans++;
            }

        }
        if (N!=1)
            ans++;
        System.out.println(ans);



    }



}
