import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int[] guest=new int[8];
			for(int i = 0; i < 8;i++){
				guest[i]=cin.nextInt();
			}
			ArrayList<Integer> list = new ArrayList<Integer>();
			list.add(4);
			list.add(1);
			list.add(4);
			list.add(1);
			list.add(2);
			list.add(1);
			list.add(2);
			list.add(1);
			int sum=0;
			int minList = 999999999;
			int minSum = 999999999;
			ArrayList<Integer> ans=new ArrayList<Integer>();
			for(int j = 0; j < 8;j++){
				sum=0;
				for(int i =0; i<8;i++){
					//System.out.print(list.get(i)+" " );
				}
				for(int i =0; i<8;i++){
					int c = guest[i]-list.get(i);
					//System.out.println(guest[i]+" " + list.get(i) + " " + c);
					if(c<=0){
						continue;
					}
					sum+=c;
				}
				//System.out.println(sum);
				if(minSum>sum){
					ans=(ArrayList<Integer>) list.clone();
					minSum=sum;
					minList=listToInt(list);
				}
				else if(minSum==sum){
					if(minList>listToInt(list)){
						ans=(ArrayList<Integer>) list.clone();
						minSum=sum;
						minList=listToInt(list);
					}
				}
				int tmp=list.remove(0);
				list.add(tmp);
			}
			System.out.print(ans.get(0));
			for(int i =1; i<8;i++){
				System.out.print(" "+ans.get(i));
			}
			System.out.println();
		}
	}
	static int listToInt(ArrayList<Integer> list){
		int ans=0;
		for(int i= 0; i < 7;i++){
			ans = ans*10 + list.get(i);
		}
		return ans;
	}
}
