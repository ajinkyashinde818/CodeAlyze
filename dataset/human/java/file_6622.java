import java.util.*;
public class Main {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc=new Scanner(System.in);
		
		Set<Integer> XSet=new TreeSet<Integer>();
		Set<Integer> YSet=new TreeSet<Integer>();
		YSet.add(0);
		boolean facingX=true;
		String s=sc.next()+"T";
		int temp=0;
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)=='F') {
				temp++;
			}
			else {
				if(facingX) {
					Object[] tempArray=XSet.toArray();
					for (Object num: tempArray) {
						XSet.remove(num);
						XSet.add((Integer)num+temp);
						XSet.add((Integer)num-temp);
					}
					if(XSet.isEmpty()) {
						XSet.add(temp);
					}
				}
				else {
					Object[] tempArray= YSet.toArray();
					for (Object num: tempArray) {
						YSet.remove(num);
						YSet.add((Integer)num+temp);
						YSet.add((Integer)num-temp);
					}
				}
				temp=0;
				facingX=!facingX;
			}
		}
		
		int x=sc.nextInt();
		int y=sc.nextInt();
		if(XSet.contains(x) && YSet.contains (y)) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
 
}
