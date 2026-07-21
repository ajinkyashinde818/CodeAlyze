import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        Arrays.sort(s);
        String sAsc = new String(s);
        char[] t = sc.next().toCharArray();
        Arrays.sort(t);
        String tAsc = new String(t);
        String tDesc = new StringBuilder(tAsc).reverse().toString();
        if(sAsc.compareTo(tDesc) < 0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
        sc.close();

    }

}
