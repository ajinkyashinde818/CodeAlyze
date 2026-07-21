import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        int q=sc.nextInt();
        StringBuilder sb=new StringBuilder(s);
        StringBuilder pre=new StringBuilder();
        int count=0;
        boolean flag=false;
        for(int i=0;i<q;i++)
        {
            int t=sc.nextInt();
            if(t==1)
            {
                count++;
                flag=!flag;
                continue;
            }
            else
            {
                int f=sc.nextInt();
                char c=sc.next().charAt(0);
                if(f==1) {
                    if (flag) {
                        sb.append(c);
                    } else {
                        pre.append(c);
                    }
                }
                else
                {
                    if (flag) {
                        pre.append(c);
                    } else {
                        sb.append(c);
                    }
                }
            }
        }
        pre.reverse().append(sb);
        if(count%2==1) {
            pre.reverse();
        }
        System.out.println(pre.toString());
    }
}
