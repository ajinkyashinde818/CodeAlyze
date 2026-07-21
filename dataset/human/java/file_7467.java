import java.util.*;
import java.util.stream.*;
class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String S = input.next();
        S = S.replaceAll("eraser","-");
        S = S.replaceAll("erase","-");
        S = S.replaceAll("dreamer","-");
        S = S.replaceAll("dream","-");
        S = S.replaceAll("-","");
        if (S.length() == 0){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
}
