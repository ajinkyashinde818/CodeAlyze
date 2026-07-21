import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        String line = readLine();
        StringTokenizer st = new StringTokenizer(line, "");
        String s = (String)st.nextToken();

        String[] strArray = s.split("");
        String a = strArray[0];
        String b = strArray[1];
        String c = strArray[2];
        if ((a.equals(b))||(a.equals(c))||(b.equals(c))) {
        	System.out.println("No");
        }else {
        	System.out.println("Yes");
        }

    }

    private static String readLine() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return br.readLine();
    }

}
