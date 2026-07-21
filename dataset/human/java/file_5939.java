import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String S =sc.next();
        int a=0,b=0,c=0;
        for(int d=0;d<3;d++){
            if(S.charAt(d)=='a') a++;
            else if(S.charAt(d)=='b')b++;
            else c++;
        }
        if(a<=1&&b<=1&&c<=1) System.out.println("Yes");
        else System.out.println("No");
    }
}
