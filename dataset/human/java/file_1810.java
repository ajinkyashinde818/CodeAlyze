import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int D = Integer.parseInt(sc.next());
    int G = Integer.parseInt(sc.next());
    int[] p = new int[D];
    int[] c = new int[D];

    for (int i=0; i < D; i++) {
      p[i] = Integer.parseInt(sc.next());
      c[i] = Integer.parseInt(sc.next());
    }
    int min = Integer.MAX_VALUE;
    out : for(int i=0; i<Math.pow(2,D); i++){
      boolean flag[] = new boolean[D];
      Arrays.fill(flag, false);
      int sum = 0; // 点数の合計
      int num = 0;//  解いた問題の合計
      for(int j=0; j<D; j++){
        if((i>>j&1)==1){
          num = num + p[j];
          sum = sum + p[j]*(j+1)*100 + c[j];
          flag[j] = true;
        }
      }
      if(sum >= G ){
        min = Math.min(min, num);
        continue out;
      }
      // in : for(int j=D-1; j>=0; j--){
      //   if(!flag[j]){
			// 		for(int k = 1; k < p[j]-1; k++) {
			// 			sum += 100 * (j+1);
			// 			num++;
			// 			if(sum >= G) {
			// 				min = Math.min(min, num);
			// 				break in;
			// 			}
      //     }    
      //   }    
        
      // }
			in : for(int j = 0; j < D; j++) {
				if(!flag[D - 1 - j]) {
					for(int k = 0; k < p[D - 1 - j]; k++) {
						sum += 100 * (D - j);
						num++;
						if(sum >= G) {
							min = Math.min(num, min);
              break in;
					
            }
					}
				}
			}
    }
    System.out.println(min);
    return;
  }
}
