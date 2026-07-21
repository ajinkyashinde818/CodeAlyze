import java.util.Scanner;

public class Main{
    static boolean ff=false;
    static long maxx(int tot,int ind,int[] c,int ulev[][],int x){
        if(ind>=c.length){
            long[] t=new long[ulev[0].length];
            for(int j=0;j<c.length;j++){
                int i= ((1<<j)&tot);
                if(i!=0){
                    for(int k=0;k<ulev[0].length;k++){
                        t[k]=t[k]+ulev[j][k];
                    }
                }
            }
            long ij=0;
            for(int j=0;j<t.length;j++){
                    if(t[j]>=x){
                        ij++;
                    }
            }
            if(ij==t.length){
                ff=true;
                return 0;
            }else{
                return Integer.MAX_VALUE;
            }

        }
        return Math.min( maxx(tot|(1<<ind),ind+1,c,ulev,x)+c[ind],maxx(tot,ind+1,c,ulev,x) );

    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int n= scanner.nextInt();
        int m=scanner.nextInt();
        int x=scanner.nextInt();
        int[] c=new int[n];
        int[][] ul=new int[n][m];
        for(int j=0;j<n;j++){
            c[j]= scanner.nextInt();
            for(int i=0;i<m;i++){
                ul[j][i]=scanner.nextInt();
            }
        }
        ff=false;
        long ans=maxx(0,0,c,ul,x);
        if(!ff){
            System.out.println(-1);
        }else{
        System.out.println(ans);
    }}

}
