import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] tokens = line.split(" ");
                int a = Integer.parseInt(tokens[0]);
                int b = Integer.parseInt(tokens[1]);
                int k = Integer.parseInt(tokens[2]);
                int i = 0;
                List<Integer> result = new ArrayList<>();
                while (i <= a && i <= b) {
                    i++;
                    if (a%i == 0 && b%i == 0) {
                        result.add(i);
                    }
                }
                System.out.println(result.get(result.size()-k));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
