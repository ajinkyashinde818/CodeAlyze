import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(buffer.readLine());
        int [][] ds = new int[n][2];
        for (int pos = 0; pos < n; pos++) {
            String [] inp = buffer.readLine().split(" ");
            ds[pos][0] = Integer.parseInt(inp[0]);
            ds[pos][1] = Integer.parseInt(inp[1]);
        }
        boolean check = false;
        for (int pos = 0; pos < n-2; pos++) {
            if(ds[pos][0] == ds[pos][1] && ds[pos+1][0] == ds[pos+1][1] && ds[pos+2][0] == ds[pos+2][1]){
                check = true;
                break;
            }
        }
        if (check)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
