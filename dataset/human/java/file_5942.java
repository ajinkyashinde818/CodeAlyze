import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] abc = s.split("");
        Arrays.sort(abc);
        s = String.join("",abc);
        System.out.println(s.equals("abc")?"Yes":"No");
        
    }
}
