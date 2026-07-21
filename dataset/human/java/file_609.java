import java.io.InputStream;
import java.util.Scanner;

/**
 * @author kanbe
 *
 */
public class Main {
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        int j = scanner.nextInt();
        
        if (i < 10) {
            j = ((100 * (10 - i)) + j);
        } 
        System.out.println(j);
        
    }

}
