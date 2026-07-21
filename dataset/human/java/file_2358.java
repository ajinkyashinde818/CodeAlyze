import javax.xml.crypto.Data;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{

        //入力
        /*
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        */
        Scanner sc = new Scanner(System.in);
        String str = sc.next();


        // 出力
        int n = str.length();
        System.out.println(str.substring(0, n - 8));
    }
}
