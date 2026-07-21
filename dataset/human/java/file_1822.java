import java.util.*;

public class Main {
	static int num=9999;
	static int d;
	static int g;
	static int p[];
	static int c[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		d = sc.nextInt();
		g = sc.nextInt();
		p = new int[d];
		c = new int[d];

		for(int i=0;i<d;i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		
		calc(0,0,0,0);
		
		System.out.println(num);
	}
	
	static void calc(int piv, int tmp_num, long tmp_sum, long check) {
		if( piv==d ) {
			if( tmp_sum<g ) {
				for(int i=d;i>0;i--) {
					// 既に解いている問題ならスルー
					if( check/(Math.pow(10,i-1))==1 || (check/(Math.pow(10,i-1)))%Math.pow(10,d-i) == 1)
						continue;
					if( tmp_sum+100*i*(p[i-1]-1) >= g ) {
						while(true) {
							tmp_num++;
							tmp_sum += 100*i;
							if(tmp_sum >= g)
								break;
						}
						break;
					}
				}
			}
			if( tmp_sum>=g && num>tmp_num && tmp_num!=0 )
				num = tmp_num;
			return;
		}
		
		// 100*piv点の問題を全て解いた場合
		calc(piv+1,tmp_num+p[piv],tmp_sum+100*(piv+1)*p[piv]+c[piv],check+(long)Math.pow(10,piv));
		// 100*piv点の問題を全く解かない場合
		calc(piv+1,tmp_num,tmp_sum,check);
	}
}
