import java.util.*; 
import java.io.*; 

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); 
        int k = scan.nextInt(); 
        if(n > 10) System.out.println(k); 
        else System.out.println(k + 100*(10-n));
        }
}
