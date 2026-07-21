import java.util.*;

public class Main{
    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      int n=sc.nextInt();
      int m=sc.nextInt();

      int flag = 1;
      int ans = 0;

      int[] a = new int[m];
      for(int i=0;i<m;i++){
        a[i]=sc.nextInt()-1;
      }

      if(m>=2){
      //////////ERROR//////////////////////
      for(int i=0;i<m-1;i++){
        if(a[i+1]==a[i]+1){
          flag = 0;
          break;
        }
      }
      ////////////////////////////////////
      }

      //////////holl record///////////////
      int[] way = new int[n];
      int ccnt=0;
      for(int i=0;i<n;i++){
        for(int j=ccnt;j<m;j++){
          if(i==a[j]){
            way[i] = -1;
            ccnt++;
            break;
          }
        }
      }
      ////////////////////////////////////

      if(n==1){
        way[0] = 1;
      }
      else if(n==2){
        if(a.length==0){
          way[0] = 1;
          way[1] = 2;
        }
        else if(a.length==1){
          way[0] = 0;
          way[1] = 1;
        }
      }
      else if(n>=3){
        if(way[0]!=-1){
          way[0] = 1;
        }
        else{
          way[0] = 0;
        }

        if(way[1]!=-1){
          if(way[0]==0){
            way[1] = 1;
          }
          else if(way[0]==1){
            way[1] = 2;
          }
        }
        else if(way[1]==-1){
          way[1] = 0;
        }

        for(int i=2;i<n;i++){
          if(way[i]!=-1){
            way[i] = way[i-1] + way[i-2];
            way[i] = way[i] % 1000000007;
          }
          else{
            way[i] = 0;
          }
        }
      }

      ans = way[n-1] % 1000000007;

      if(flag==0){
        System.out.println("0");
      }
      else{
        System.out.println(ans);
      }

      for(int i=0;i<n;i++){
        //System.out.println("way["+i+"]="+way[i]);
      }
    }
}
