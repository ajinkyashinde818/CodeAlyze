import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        
        if(line.contains("a") && line.contains("b") && line.contains("c")){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
