import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        long n=Long.parseLong(br.readLine());
        StringTokenizer st=new StringTokenizer(br.readLine());
        long[] a=new long[(int)n];
        long sum=0;
        long count=0;
        for(int i=0;i<n;i++){ a[i]=Long.parseLong(st.nextToken()); sum+=a[i]; }
        if(sum%((n*(n+1))/2)!=0){
            System.out.println("NO");
            System.exit(0);
        }
        long times=sum/((n*(n+1))/2);
        for(int i=0;i<n;i++){
            count=(a[(i+1)%(int)n]-a[i]);
            if((count>times)||(times-count)%n!=0){
                System.out.println("NO");
                System.exit(0);
            }
        }System.out.println("YES");
    }
}
