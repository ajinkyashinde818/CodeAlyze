import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(),m = sc.nextInt();
    String a[] = new String[n];
    String b[] = new String[m];
    for(int i = 0;i < n;i++){
      a[i] = sc.next();
    }
    for(int i = 0;i < m;i++){
      b[i] = sc.next();
    }
    int ans = 0;
    //こっから捜索開始
    int count = 0;
    for(int i = 0;i<n-m+1;i++){//b箱を縦にさげる
      for(int j = 0;j<n-m+1;j++){//b箱を右にずらす
        count = 0;
        for(int k = 0;k<m;k++){//bの行を下げる
          if(b[k].equals(a[i+k].substring(j,j+m ) ) ){
            count++;
          }
          if(count == m){//最後までいききったらおっけー
            ans=1;
          }
        }
      }
    }
    if(ans==1){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
