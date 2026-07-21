import java.util.Scanner;

/**
 *
 * @author C0117306
 */
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String x = sc.next();
        int cx=0,cy=0;
        String y=sc.next();
        String[] hai={"A","B","C","D","E","F"};
        for (int i = 0; i < hai.length; i++) {
            if (x.equals(hai[i])) {
               cx=i;
            }
            if (y.equals(hai[i])) {
                cy=i;
            }
        }
        if(cx<cy){
            System.out.println("<");
        }else if(cx>cy){
            System.out.println(">");
        }else{
            System.out.println("=");
        }
       
    }
    
}
