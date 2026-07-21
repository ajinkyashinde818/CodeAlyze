import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] carr = br.readLine().toCharArray();
        int len = carr.length;
        int res = 0;
        int i = 0;
        int j = len-1;
        while(i < j){
            char left = carr[i];
            char right = carr[j];
            if(left == right){
                ++i;
                --j;
                continue;
            }
            if(left != 'x' && right != 'x'){
                System.out.println(-1);
                return;
            }
            else if(left == 'x'){
                ++res;
                ++i;
            }
            else if(right == 'x') {
                ++res;
                --j;
            }
        }
        System.out.println(res);
    }
}
