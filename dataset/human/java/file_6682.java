import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int array[] = new int[n + 1];
        long sum = 0;
        for(int i = 1;i <= n;i++){
            int a = Integer.parseInt(st.nextToken());
            array[i] = a;
            sum += a;
        }
        if(sum * 2 % (n * 1L * (n + 1)) != 0){
            System.out.println("NO");
            return;
        }
        long times = sum * 2 / (n * 1L * (n + 1));
        int cnt = 0;
        array[0] = array[n];
        for(int i = 1;i <= n;i++){
            long diff = array[i] - array[i - 1] - times;
            if(diff > 0){
                System.out.println("NO");
                return;
            }
            if(diff < 0){
                if(Math.abs(diff) % n > 0){
                 System.out.println("NO");
                 return;
                }
                cnt += Math.abs(diff)/n;
            }
        }
        if(cnt > times){
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
    }
}
