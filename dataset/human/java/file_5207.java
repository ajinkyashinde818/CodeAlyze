import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        LinkedList<Character> s = new LinkedList<>();
        for (char chara : in.readLine().toCharArray()) {
            s.add(chara);
        }
        boolean reversed = false;
        for (int q = Integer.parseInt(in.readLine()); q > 0; q--) {
            StringTokenizer tokenizer = new StringTokenizer(in.readLine());
            if (tokenizer.nextToken().equals("1")) {
                reversed = !reversed;
            } else {
                int f = Integer.parseInt(tokenizer.nextToken());
                if (reversed) {
                    f = 3 - f;
                }
                char chara = tokenizer.nextToken().charAt(0);
                if (f == 1) {
                    s.addFirst(chara);
                } else {
                    s.addLast(chara);
                }
            }
        }
        StringBuilder builder = new StringBuilder();
        for (char chara : s) {
            builder.append(chara);
        }
        if (reversed) {
            builder.reverse();
        }
        System.out.println(builder);
    }
}
