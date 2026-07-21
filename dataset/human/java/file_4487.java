import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{
    public static void main(String[] args) throws IOException
    {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        Integer[] abc =
            Arrays.stream(reader.readLine().split(" ")).map(x -> Integer.parseInt(x)).toArray(Integer[]::new);

        if (abc[2] <= abc[0] + abc[1])
        {
            System.out.println(abc[2] + abc[1]);
        }
        else
        {
            System.out.println(abc[0] + 2 * abc[1] + 1);
        }
    }
}
