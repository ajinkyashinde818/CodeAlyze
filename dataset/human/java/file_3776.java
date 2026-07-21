import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;
import java.util.StringJoiner;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        List<String> values = IO.readLineAsList();
        char x = values.get(0).charAt(0);
        char y = values.get(1).charAt(0);
        if( x - y < 0 ) {
            IO.writeLine("<");

        } else if ( x == y ) {
            IO.writeLine("=");

        } else {
            IO.writeLine(">");
        }
    }

    @SuppressWarnings("unused")
    public static class IO {

        private static BufferedReader br;

        private static BufferedReader br() {
            if( br == null ) {
                br = new BufferedReader( new InputStreamReader(new BufferedInputStream(System.in), StandardCharsets.UTF_8) );
            }
            return br;
        }

        public static String readLine() {
            try {
                return br().readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public static int readLineAsInt() {
            return Integer.parseInt(readLine());
        }

        public static List<String> readLineAsList() {
            return Arrays.asList( readLine().split(" "));
        }

        public static List<Integer> readLineAsIntList() {
            return readLineAsList().stream()
                    .map( Integer::parseInt )
                    .collect(Collectors.toList());
        }

        public static void writeLine(String line) {
            System.out.println( line );
        }

        public static void writeLine(List<Integer> values) {
            StringJoiner j = new StringJoiner(" ");
            values.forEach(i -> j.add(String.valueOf(i)) );
            writeLine(j.toString());
        }

        public static void writeLines(List<String> lines) {
            lines.forEach(System.out::println);
        }
    }
}
