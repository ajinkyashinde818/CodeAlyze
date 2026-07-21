import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException
    {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
        String s = r.readLine();
        if(s.contains("a") && s.contains("b") && s.contains("c"))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}
