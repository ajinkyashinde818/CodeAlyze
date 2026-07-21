import java.util.*;
class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next()),b=Integer.parseInt(sc.next());
        if(a<b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        long tmpA = a,tmpB = b,tmp=0;
        while((tmp=tmpA%tmpB)!=0){
            tmpA = tmpB;
            tmpB = tmp;
        }
        long ans = (a/tmpB)*b;
        System.out.println(ans);
    }
}
