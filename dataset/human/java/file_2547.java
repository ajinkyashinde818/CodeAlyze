import java.util.*;
public class Main{
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        Arrays.sort(s);
        Arrays.sort(t);
        String sort_s = String.valueOf(s);
        String sort_t = String.valueOf(t);

        String sort_rev_t = new StringBuilder(sort_t).reverse().toString();

        if(sort_s.compareTo(sort_rev_t) < 0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

    }
    
}
