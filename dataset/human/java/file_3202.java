import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int first = N%10;
        int tenth = N/10;
        sc.close();
            
        if(first == 9 || tenth == 9){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
