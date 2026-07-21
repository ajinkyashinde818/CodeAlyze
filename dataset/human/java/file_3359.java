import java.io.*;
import java.io.InputStreamReader;
import java.util.*;
public class Main
{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = n % 10;
        if(a == 9 || (n / 10) == 9)System.out.print("Yes");
        else System.out.print("No");

    }

}
