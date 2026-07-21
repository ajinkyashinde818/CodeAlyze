import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        String[] inputs = reader.readLine().split(" ");
        int X = Integer.parseInt(inputs[0], 16);
        int Y = Integer.parseInt(inputs[1], 16);
        if (X == Y) {
            System.out.println("=");
        } else if (X < Y) {
            System.out.println("<");
        } else {
            System.out.println(">");
        }
    }
}
