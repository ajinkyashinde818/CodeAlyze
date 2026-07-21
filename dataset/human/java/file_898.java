import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner scan = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        
		int n = scan.nextInt();
		int r = scan.nextInt();
        
        out.println(n >= 10 ? r : r + (100 * (10 - n)));
        out.close();
        
    }
}
