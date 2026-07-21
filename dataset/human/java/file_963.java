import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Main{

    static class sushi{
        long x,v;
        sushi(long x,long v){
            this.x=x;
            this.v=v;
        }

    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N  =scan.nextInt();
        long C = scan.nextLong();
        List<sushi> sushis = new ArrayList<>();
        for(int i=0;i<N;++i){
            long x = scan.nextLong();
            long v = scan.nextLong();
            sushis.add(new sushi(x,v));
        }
        Collections.sort(sushis,(a,b)-> a.x<b.x ? -1:1);
        long lmax[] = new long[N];
        long retlmax[] = new long[N];
        long rmax[] = new long[N];
        long retrmax[] = new long[N];

        long tmp=0;
        for(int i=0;i<N;++i){
            tmp += sushis.get(i).v;
            retlmax[i] = Math.max(i>0 ? retlmax[i-1]:0, tmp-sushis.get(i).x*2);
            lmax[i] = Math.max(i>0 ? lmax[i-1]:0, tmp-sushis.get(i).x);
        }
        tmp = 0;
        for(int i=N-1;i>=0;--i){
            tmp += sushis.get(i).v;
            retrmax[i] = Math.max(i<N-1 ? retrmax[i+1]:0, tmp-(C-sushis.get(i).x)*2);
            rmax[i] = Math.max(i<N-1 ? rmax[i+1]:0, tmp-(C-sushis.get(i).x));
        }
        long ans = Math.max(lmax[N-1], rmax[0]);
        for(int i=0;i<N-1;++i)ans = Math.max(ans,retlmax[i]+rmax[i+1]);
        for(int i=1;i<N;++i)ans = Math.max(ans, retrmax[i]+lmax[i-1]);
        System.out.println(ans);

    }
}
