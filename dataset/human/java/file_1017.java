import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;import java.util.Collections;

 
public class Main {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
	    int word=Integer.parseInt(reader.readLine());
	    System.out.println(word*32);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
