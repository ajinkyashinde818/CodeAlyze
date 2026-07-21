import java.util.*;
import java.io.*;
class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Integer K = Integer.parseInt(st.nextToken());
        Integer S = Integer.parseInt(st.nextToken());
        long ans=0;
        for (int i=0; i<=K; i++) {

            for (int j=0; j<=K; j++) {
                if(i+j>S)
                    continue;
                if(S-i-j<=K)
                    ans++;
            }
        }
        System.out.println(ans);
        
    }

}
