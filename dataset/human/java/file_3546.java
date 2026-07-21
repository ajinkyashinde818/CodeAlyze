import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            final String s = reader.readLine();

            final String sl[] = s.split(" ");
            char X = sl[0].charAt(0);
            char Y = sl[1].charAt(0);

            System.out.println(
                X < Y ? "<" : Y < X ? ">" : "=");
        }
    }
}
