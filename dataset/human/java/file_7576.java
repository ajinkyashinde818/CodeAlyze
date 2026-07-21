import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static int MOD=1000000007;
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        String s=sc.next();
        char[] d={'m','a','e','r','d'};
        char[] dr={'r','e','m','a','e','r','d'};
        char[] e={'e','s','a','r','e'};
        char[] er={'r','e','s','a','r','e'};
        int dream=0,dreamer=0,erase=0,eraser=0,temp;
        int n=s.length(),count=0;
        for (int i = 0; i < n; i++) {
            temp=dream+erase+dreamer+eraser;
            char p=s.charAt(n-i-1);
            if(p==d[dream])dream++;
            if(p==dr[dreamer])dreamer++;
            if(p==e[erase])erase++;
            if(p==er[eraser])eraser++;
            count++;
            if(temp==dream+dreamer+erase+eraser){
                out.println("NO");
                exit(0);
            }
            if(count!=max(max(dream,dreamer),max(erase,eraser))){
                out.println("NO");
                exit(0);
            }
            if(dreamer==7||dream==5||erase==5||eraser==6){
                dream=dreamer=erase=eraser=count=0;
            }
        }
        out.println("YES");
    }
}
