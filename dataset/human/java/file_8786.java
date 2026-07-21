import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String args[]) throws Exception{
        BufferedReader stdR = new BufferedReader(new InputStreamReader(System.in));
        String[] str = stdR.readLine().split(" ");
        int A = Integer.parseInt(str[0]);
        int B = Integer.parseInt(str[1]);
        int K = Integer.parseInt(str[2]);
        int num = 1;
        int count = 0;
        ArrayList<Integer> ast = new ArrayList<Integer>();
        while(num <= Math.min(A, B)) {
            if(A % num == 0 && B % num == 0) {
                ast.add(num);
            }
            num++;
        }
        System.out.println(ast.get(ast.size() - K));
    }
}
