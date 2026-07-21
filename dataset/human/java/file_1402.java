import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
public static void main(String[] args){
Scanner sc = new Scanner(in);
int n = Integer.parseInt(sc.next());
int m = Integer.parseInt(sc.next());
String[] sn=new String[n];
String[] sm=new String[m];
for (int i = 0; i < n; i++) {sn[i]=sc.next();}
for (int i = 0; i < m; i++) {sm[i]=sc.next();}
int c=0;
for(int k=0;k<=n-m;k++){
    for(int i=0;i<=n-m;i++){
        c=0;
        for(int j=0;j<m;j++){
            if(sn[i+j].substring(k,k+m).equals(sm[j]))c++;
        }
        if(c==m)break;
    }
    if(c==m)break;
}
if(c==m){
    out.println("Yes");
}else{
    out.println("No");
}
}}
