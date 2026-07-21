import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        StringBuffer str = new StringBuffer(S);
        S = str.reverse().toString();
        int i = 0;
        int len = S.length();
        while(true) {
            if(len - i >= 5 && S.substring(i, i+5).equals("esare")) {
                //S = S.replace("esare","");
                i += 5;
            }else if(len - i >= 5 && S.substring(i, i+5).equals("maerd")) {
                //S = S.replace("maerd","");
                i+= 5;
            }else if(len - i >= 7 && S.substring(i, i+7).equals("remaerd")) {
                //S = S.replace("remaerd","");
                i += 7;
            }else if(len - i >= 6 && S.substring(i, i+6).equals("resare")) {
                //S = S.replace("resare","");
                i += 6;
            }else {
                break;
            }
        }
        if(i == len) System.out.println("YES");
        else System.out.println("NO");
    }
}
