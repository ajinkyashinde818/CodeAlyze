import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str[]=br.readLine().split(" ");
        int k=Integer.parseInt(str[0]);
        int s=Integer.parseInt(str[1]);
        
        int result=0;
        
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                if(s-i-j>=0&&s-i-j<=k)
                    result++;
            }
        }
        
        System.out.println(result);
    }
}
