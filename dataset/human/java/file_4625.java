import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(),b=sc.nextInt(),c=sc.nextInt();
        long ans = 0;
        ans += 2*Math.min(b,c);
        b -= ans/2;
        c -= ans/2;
        if(b>0){
            ans += b;
        }else{
            if(a>c-1) ans += c;
            else ans += a+1;
        }
        System.out.println(ans);
    }
}
