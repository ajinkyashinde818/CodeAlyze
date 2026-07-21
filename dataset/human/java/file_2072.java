import java.util.Map.Entry;
import java.util.*;
import java.math.*;
import org.w3c.dom.css.Counter;
  
public class Main{
    public static void main(final String[] args){
 
        final Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        int ans=0;
        long q =2;
 
        //1だった時はさっさと終わらす
        if(N==1){
            System.out.println(0);
            return;
        }
 
        //本編
        while(q*q<=N){
            //qを決定する
            if(N%q ==0){
                //qの累積を全部発見する
                for(int i = 1; N>=Math.pow(q,i);i++){
                    if(N%Math.pow(q, i)==0){
                        //発見するたびにカウントアップ
                        ans++;
                        //発見するたびに除算
                        N = (long) (N / Math.pow(q, i));
                    }
                }
                //qの累積は見つけ尽くしたので、Nからqを完全に取り除く
                while(N%q ==0){
                    N = N/q;
                }
            }   
            q++;
        }

        //1以外の数が搾りカスとして出たら足してあげる
        if(N != 1){ans++;}
            System.out.println(ans);
    }
}
