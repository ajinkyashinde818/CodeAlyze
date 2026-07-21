import java.util.Scanner;

/**
 *
 * @author lenovo
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        String ans = "Yes";
                
        int in  = str.indexOf("9");
        if (in == -1) {
            ans = "No";
        }
        
        System.out.println(ans);
    }
    
}
