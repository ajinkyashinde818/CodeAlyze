import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        boolean ok = s.matches("(dream(er)?|eraser?|)+");
        System.out.println(ok?"YES":"NO");
    }
}
