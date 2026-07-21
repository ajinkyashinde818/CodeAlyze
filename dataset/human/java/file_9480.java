import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(),d=0,cur=0;
        for(int i=0;i<n;i++){
            int d1=in.nextInt(),d2=in.nextInt();
            if(d1==d2){
                cur++;
            }
            else{
                d=Math.max(d,cur);
                cur=0;
            }
        }
        d=Math.max(cur,d);
        if(d>=3)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
