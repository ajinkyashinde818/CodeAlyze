import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();	//湖の円周（Kメートル）
        int n = scan.nextInt();	//家の数（N軒）
        int space = 0;
        int[] a;				//家の北側からの時計回りの距離(1, 2, 3...N)
        a = new int[n];

//		System.out.println("k="+k);
//		System.out.println("n="+n);
//		System.out.println("space="+space);

        for (int i=0; i<n; i++) {
        	a[i] = scan.nextInt();
        }

        space = (k-a[n-1])+a[0];		//家と家との間の距離
//		System.out.println("space="+space);

        for (int i=0; i<n-1; i++) {
 			if(space<(a[i+1]-a[i])) {
 				space = (a[i+1]-a[i]);
 			}       
        }
        
        // 全体（Kメートル）-（間が一番空いている距離）= （答え）
		System.out.println(k-space);
	    scan.close();	
    }
}
