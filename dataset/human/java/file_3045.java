import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Abhilash Mandaliya
 */
public class Main {
    public static void main (String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader( inputStream );
        PrintWriter out = new PrintWriter( outputStream );
        TaskC solver = new TaskC();
        solver.solve( 1, in, out );
        out.close();
    }

    static class TaskC {
        public void solve (int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            boolean s = false, e = false;
            String possible = "POSSIBLE", impossible = "IMPOSSIBLE";
            Set<Integer> destination = new HashSet<>();
            Set<Integer> origin = new HashSet<>();
            for ( int i = 0; i < m; i++ ) {
                int u = in.nextInt();
                int v = in.nextInt();
                if ( ( u == 1 && v == n ) ) {
                    out.print( possible );
                    return;
                }
                if ( u == 1 )
                    origin.add( v );
                if ( v == 1 )
                    origin.add( u );
                if ( u == n )
                    destination.add( v );
                if ( v == n )
                    destination.add( u );
            }
            Iterator<Integer> destinationIterator = destination.iterator();
            while ( destinationIterator.hasNext() ) {
                int next = destinationIterator.next();
                if ( origin.contains( next ) ) {
                    out.println( possible );
                    return;
                }
            }
            out.println( impossible );
        }

    }

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar;
        private int snumChars;

        public InputReader (InputStream st) {
            this.stream = st;
        }

        public int read () {
            if ( snumChars == - 1 )
                throw new InputMismatchException();
            if ( curChar >= snumChars ) {
                curChar = 0;
                try {
                    snumChars = stream.read( buf );
                } catch ( IOException e ) {
                    throw new InputMismatchException();
                }
                if ( snumChars <= 0 )
                    return - 1;
            }
            return buf[curChar++];
        }

        public int nextInt () {
            int c = read();
            while ( isSpaceChar( c ) ) {
                c = read();
            }
            int sgn = 1;
            if ( c == '-' ) {
                sgn = - 1;
                c = read();
            }
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while ( ! isSpaceChar( c ) );
            return res * sgn;
        }

        public boolean isSpaceChar (int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == - 1;
        }

    }
}
