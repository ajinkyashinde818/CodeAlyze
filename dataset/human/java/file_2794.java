import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		String t = scan.next();
		String sD = "";
		String tD = "";
		List<String> sList = new ArrayList<String>();
		List<String> tList = new ArrayList<String>();
		List<String> list = new ArrayList<String>();
		for(int i = 0; i < s.length(); i++) {
			sList.add(s.substring(i, i + 1));
		}
		for(int i = 0; i < t.length(); i++) {
			tList.add(t.substring(i, i + 1));
		}
		Collections.sort(sList);
		Collections.sort(tList, Collections.reverseOrder());
		for(int i = 0; i < sList.size(); i++) {
			sD += sList.get(i);
		}
		for(int i = 0; i < tList.size(); i++) {
			tD += tList.get(i);
		}
		list.add(sD);
		list.add(tD);
		Collections.sort(list);
		if(sD.equals(list.get(0)) && !sD.equals(tD)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		scan.close();

	}

}
