import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    private static final StringBuilder builder = new StringBuilder();
    public static void main(String[] args) {
        long n = readLong();
        double sqrt = Math.sqrt(n);
        if (n == 1) {
            System.out.print(0);
            return;
        }

        if (n < 6) {
            System.out.print(1);
            return;
        }

        HashMap<Integer, Integer> smap = new HashMap<>();
        for (int i = 2; n > 1 && i <= sqrt; i++) {
            int j = 0;
            while (n % i == 0) {
                j++;
                n /= i;
            }
            if (j > 0) {
                smap.put(i, j);
            }
        }
        
        if (n != 1) smap.put((int) n, 1);

        int count = 0;

        for (int i : smap.keySet()) {
            int j = smap.get(i);
            if (j < 3) {
                count += 1;
            } else if (j < 6) {
                count += 2;
            } else if (j < 10) {
                count += 3;
            } else if (j < 15) {
                count += 4;
            } else if (j < 21) {
                count += 5;
            } else if (j < 28) {
                count += 6;
            } else if (j < 36) {
                count += 7;
            } else {
                count += 8;
            }
        }

        System.out.print(count);
    }

    private static void read() {
        builder.setLength(0);
        while (true) {
            try {
                int b = System.in.read();
                if (b == ' ' || b == '\n' || b == -1) {
                    break;
                } else {
                    builder.appendCodePoint(b);
                }
            } catch (IOException e) {
                break;
            }
        }
    }

    private static int readInt() {
        read();
        return Integer.parseInt(builder.toString());
    }

    private static int readInt(int radix) {
        read();
        return Integer.parseInt(builder.toString(), radix);
    }

    private static long readLong() {
        read();
        return Long.parseLong(builder.toString());
    }

    private static long readLong(int radix) {
        read();
        return Long.parseLong(builder.toString(), radix);
    }

    private static BigInteger readBigInteger() {
        read();
        return new BigInteger(builder.toString());
    }

    private static BigInteger readBigInteger(int radix) {
        read();
        return new BigInteger(builder.toString(), radix);
    }

    private static void skipLine() {
        while (true) {
            try {
                int b = System.in.read();
                if (b == '\n' || b == -1) {
                    break;
                }
            } catch (IOException e) {
                break;
            }
        }
    }

    private static void skip() {
        while (true) {
            try {
                int b = System.in.read();
                if (b == ' ' || b == '\n' || b == -1) break;
            } catch (IOException e) {
                break;
            }
        }
    }
}
