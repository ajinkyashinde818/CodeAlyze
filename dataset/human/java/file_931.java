import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String data = sc.nextLine();
        
        String[] array = data.split(" ");
        int n = Integer.parseInt(array[0]);
        int r = Integer.parseInt(array[1]);
        
        int result = 0;
        
        if(n >= 10)
        {
            result = r;
        }
        else
        {
            result = r + 100 * (10 - n);
        }
        System.out.println(result);
    }
}
