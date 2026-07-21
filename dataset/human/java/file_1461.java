import java.util.*;

public class Main {

    static int MOD = 1000000007;
    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        String[] a=new String[n];
        String[] b=new String[m];

        for(int i=0;i<n;i++)a[i]=sc.next();
        for(int i=0;i<m;i++)b[i]=sc.next();

        boolean ok = true;
        for(int i=0;i<n-m+1;i++){//Aの縦移動
            System.out.println();
            for(int j=0;j<n-m+1;j++){//Aの横移動
                ok=true;
                for(int k=0;k<m;k++) {//Bの縦移動
                    //System.out.println(a[k+i].substring(j, j + m)+" "+b[k]);
                    if (ok&&!b[k].equals(a[k+i].substring(j, j + m))){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");

    }

}
