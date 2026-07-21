import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		String[] tokens = in.readLine().split(" ");
		char X = tokens[0].charAt(0);
		char Y = tokens[1].charAt(0);

		String str = "";
		if (X == Y) {
			str = "=";
		} else if (X < Y) {
			str = "<";
		} else {
			str = ">";
		}
		System.out.println(str);
	}
}
