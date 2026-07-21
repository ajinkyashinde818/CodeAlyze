import java.util.Map.Entry;
import java.util.*;
import java.math.*;
import org.w3c.dom.css.Counter;


public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		long k= Long.parseLong(sc.next());
		
		int[] aList=new int[n];
		long[] position=new long[n];
		
		for(int i=0;i<n;i++){
			aList[i]=sc.nextInt();
		}
		
        ArrayList<Integer> list=new ArrayList<>();
        //開始町番号
        int listNum=1;
        //移動回数
        long steps=1;
        //最初の移動が終わったところから開始！
        list.add(1);
        //位置設定：初期町
		position[0]=1;
		while(true){
            //K に到着したらやめ
            if(steps==k){
                System.out.println(aList[listNum-1]);
                break;
            }
            //ワープ先確認
			if(position[listNum-1]>1){
                //ワープ先が来訪済み
                //最後に来訪した日を取得
                long prev=position[listNum-1];
                //サイクルmod取得
                int cycleMod=(int)((k-prev+1)%(steps-prev));
				int ans=list.get((int)(prev+cycleMod-1));
				System.out.println(ans);
				break;
			}
			else {
                //来た日を記録
                position[listNum-1]=steps;
                //最新航路取得
                listNum=aList[listNum-1];
                //航路情報追加
				list.add(listNum);
				//一回移動
                steps++;
			}
		}
	}
}
