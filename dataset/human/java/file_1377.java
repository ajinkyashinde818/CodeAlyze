import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
 
public class Main {
	static String[] Lb;
	private static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
    int N = in.nextInt(); // the number of cells on the Y axis
    int X = in.nextInt(); // the number of cells on the Y axis
    List<String>  lineA= new ArrayList<>();
    List<String>  lineB= new ArrayList<>();
    in.nextLine();
    int count = 0;
    while(count< N){
        lineA.add(in.nextLine());
    count++;
    }
    count =0;
    while(count< X){
        lineB.add(in.nextLine());
    count++;
    }
      System.out.println(recalTo(lineA,lineB));
}
	static int cal (int N,int X){
		int L = 0;
		L = N + X;
		L += (N-X)/X * 2 -X * 2;
		return L;
	}
	//文字列比較 何文字目から一致しているかを返す
	public static int recal(String A , String B ,int i ,boolean trig){
		if(B.length() + i > A.length()){
			return -1;
		}
		if(A.substring(i, i + B.length()).equals(B)){
			return i;
		}else{
			if(trig){
				return recal(A,B,++i, trig);
			}else{
				return -1;
			}
		}
	}
	
	public static boolean matchList(List<String> LA , List<String> LB ,int indexA){
		boolean trig = false;
		int indexB = 0;
		int length = 0;
		int length1 = 0;
		for(String A : LA){
			A = A.substring(indexA);
			String B = LB.get(indexB);
			if((length = recal(A,B,length, trig)) != -1){
				if(!trig){
					length1 = length;
				}
				trig = true;
				indexB++;
				if(length1 != length){
					trig = false;
					indexB = 0;
					length = 0;
				}
			}else{
				trig = false;
				indexB = 0;
				indexA = 0;
				length = 0;
			}
			if(trig && indexB == LB.get(0).length()){
				return true;
			}
		}
		return false;
	}
	public static String recalTo(List<String> LA , List<String> LB){
		//Aの続きから検索を再開したい。
		List<String> AA = LA;
		int index = 0;
		while(true){
			if(AA.isEmpty()){
				break;
			}
			if(matchList(LA, LB, index)){
				return "Yes";
			}
			index++;
			if(LA.get(0).length() <= index){
				LA.remove(0);
				index = 0;
			}
		}
		return "No";
	}
}
