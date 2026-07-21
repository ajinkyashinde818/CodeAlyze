import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException {
	// 2020/2/24 Beginner
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String[] strArray = br.readLine().split(" ");
	int N = Integer.parseInt(strArray[0]);
	int R = Integer.parseInt(strArray[1]);
	if (N >= 10)
	    System.out.println(R);
	else
	    System.out.println(100 * (10 - N) + R);
    }
}
