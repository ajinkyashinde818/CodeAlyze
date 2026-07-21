import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.System.in;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        String N = reader.readLine();
        if(N.contains("9")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
