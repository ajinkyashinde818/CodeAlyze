import java.util.*;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);     
      int N = sc.nextInt();
      boolean[] J = new boolean[N];
      int[] D1 = new int[N];
      int[] D2 = new int[N];
      for(int i = 0;i<N;i++){
        D1[i]=sc.nextInt();
        D2[i]=sc.nextInt();
        J[i]=D1[i]==D2[i];
      }
      int R = 0;
      boolean re=false;
      for(int i = 0;i<N;i++){
        if(J[i]){
          R++;
        }else{
          R=0;
        }
        if(R>2){
          re=true;
          break;
        }
      }
                         if(re){
                           System.out.println("Yes");
                         }else{
                           System.out.println("No");
                         }
   }
}
