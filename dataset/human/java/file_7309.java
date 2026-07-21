import java.io.*;
import java.util.*;
//import java.util.stream.*;
//import java.math.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(System.in);
        String s = br.readLine();
        s = s.replace("eraser", "");
        s = s.replace("erase", "");
        s = s.replace("dreamer", "");
        s = s.replace("dream", "");
        System.out.println(s.length() > 0 ? "NO" : "YES");
        bw.flush();
    }
}
