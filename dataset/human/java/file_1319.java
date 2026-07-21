import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        String[] a=new String[n];
        String[] b=new String[m];
        boolean tmp;
        for(int i=0;i<n;i++){
            a[i]=sc.next();
        }
        for(int i=0;i<m;i++){
            b[i]=sc.next();
        }
        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                tmp=true;
                for(int k=0;k<m;k++){
                    tmp=tmp&&a[j+k].substring(i,i+m).equals(b[k]);
                }
                if(tmp){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}
