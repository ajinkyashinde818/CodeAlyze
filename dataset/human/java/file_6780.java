import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

public class Main{
    public static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    public static int nextInt() {
        try {
            in.nextToken();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return (int) in.nval;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int k = nextInt(), n = nextInt(), max = Integer.MIN_VALUE, a[] = new int[k];
        a[0] = nextInt();
        for (int i = 1; i < n; i++) {
            a[i] = nextInt();
            int x = a[i] - a[i - 1];
            if (max < x)
                max = x;
        }
        max = Math.max(a[0] + k - a[n - 1], max);
        System.out.println(k - max);
    }

}
