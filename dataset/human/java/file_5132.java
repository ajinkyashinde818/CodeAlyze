import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s = br.readLine();
        int q = Integer.parseInt(br.readLine());

        StringBuilder h = new StringBuilder();
        StringBuilder t = new StringBuilder();

        boolean v = true;
        for (int i = 0; i < q; i++) {
            String line = br.readLine();
            if (line.startsWith("1")) {
                v = !v;
            } else {
                String[] split = line.split(" ");
                String c = split[2];
                if (split[1].equals("1")) { // add C to head
                    if (v) {
                        h.append(c);
//                        heads.add(c);
                    } else {
                        t.append(c);
//                        tails.add(c);
                    }
                } else {  // add C to tail
                    if (v) {
                        t.append(c);
//                        tails.add(c);
                    } else {
                        h.append(c);
//                        heads.add(c);
                    }
                }
            }
        }

        if (v) {
//            StringBuilder out = new StringBuilder();
//            for (String head : heads) {
//                out.insert(0, head);
//            }
//            StringBuilder outt = new StringBuilder();
//            for (String tail : tails) {
//                outt.append(tail);
//            }
//            System.out.println(out.toString() + s + outt.toString());
            System.out.println(h.reverse().toString() + s + t.toString());
        } else {
//            StringBuilder out = new StringBuilder();
//            for (String head : heads) {
//                out.append(head);
//            }
//            StringBuilder outt = new StringBuilder();
//            for (String tail : tails) {
//                outt.insert(0, tail);
//            }
//            System.out.println(outt.toString()
//                    + new StringBuffer(s).reverse().toString() + out.toString());
            System.out.println(t.reverse().toString() + new StringBuilder(s).reverse().toString() + h.toString());
        }
    }
}
