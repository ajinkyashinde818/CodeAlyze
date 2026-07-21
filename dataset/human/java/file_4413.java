import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        String strStdIn = in.readLine();
        int n = Integer.parseInt(strStdIn);
        
        strStdIn = in.readLine();
        
        ArrayList<String[]> list = new ArrayList<String[]>();
        
        while(strStdIn!=null){ 
            String[] data = strStdIn.split(" ");
            list.add(data);

            strStdIn = in.readLine();
        }
        
        int sum = 0;
        int pre = -10;
        for(int i = 0; i < n; i++) {
            int eat = Integer.parseInt(list.get(0)[i]);
            if (eat-1 == pre) {
                sum += Integer.parseInt(list.get(2)[pre-1]);
            }
            pre = eat;
            sum += Integer.parseInt(list.get(1)[eat-1]);
        }
        
        System.out.println(sum);
    }
}
