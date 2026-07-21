import java.util.*;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
 
   int N = sc.nextInt();
   int M = sc.nextInt();
   boolean[] one_to_i = new boolean[N+1];
   boolean[] i_to_n = new boolean[N+1];
   int tmpa = 0;
   int tmpb = 0;
   for(int i=0;i<M;i++)
   {
     tmpa = sc.nextInt();
     tmpb = sc.nextInt(); 
     if(tmpa==1) one_to_i[tmpb] = true;
     if(tmpb==N) i_to_n[tmpa] = true;
   }
   boolean forans = false;
   String ans = "IMPOSSIBLE";
   for(int i=1;i<N;i++)
   {
     if(one_to_i[i])
     {
       if(i_to_n[i]) 
       {
         forans = true;
         break;
       }
     }
   }
   if(forans) ans = "POSSIBLE"; 
   System.out.println(ans);
 }
}
