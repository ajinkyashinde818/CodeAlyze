import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Integer x = Integer.parseInt(st.nextToken());

        if (x<1200)
            System.out.println("ABC");
        else
            System.out.println("ARC");

    }


}
