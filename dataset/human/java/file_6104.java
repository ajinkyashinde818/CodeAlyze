import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.lang.Math.*;
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        HashMap<Integer,Integer> mem = new HashMap<>();
        int k = in.nextInt();
        int s = in.nextInt();
        int x = Math.min(s,k);
        int total=0 ;
        for(int i =0;i<=x;i++){
            for(int j=0;j<=x;j++){
                int sum = i+j;
                if(sum<=s && sum+x>=s)
                    total++;
            }
        }
        System.out.print(total);
    }
}
