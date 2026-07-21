import java.util.*;


public class Main {
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			char [] c = sc.next().toCharArray();
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			int ind = 0, count = 0;
			ArrayList<Integer> xlist = new ArrayList<>();
			ArrayList<Integer> ylist = new ArrayList<>();
			for(int i = 0; i < c.length; i++){
				if(c[i] == 'F'){
					count++;
				}
				else{
					if(ind % 2 == 0){
						xlist.add(count);
						count = 0;
					}
					else{
						ylist.add(count);
						count = 0;
					}
					ind++;
				}
			}
			if(count > 0){
				if(ind % 2 == 0){
					xlist.add(count);
					count = 0;
				}
				else{
					ylist.add(count);
					count = 0;
				}
			}
			
			int len = 8100;
			boolean [][] dpx = new boolean[xlist.size() + 1][len * 2];
			dpx[0][len] = true;
			for(int i = 0; i < xlist.size(); i++){
				for(int j = 0; j < len * 2; j++){
					if(dpx[i][j] == false) continue;
					dpx[i + 1][j + xlist.get(i)] = true;
					if(i != 0){
						dpx[i + 1][j - xlist.get(i)] = true;
					}
				}
			}
			
			boolean [][] dpy = new boolean[ylist.size() + 1][len * 2];
			dpy[0][len] = true;
			for(int i = 0; i <ylist.size(); i++){
				for(int j = 0; j < len * 2; j++){
					if(dpy[i][j] == false) continue;
					dpy[i + 1][j + ylist.get(i)] = true;
					dpy[i + 1][j - ylist.get(i)] = true;
				}
			}
			
			if(dpx[xlist.size()][x + len] && dpy[ylist.size()][y + len]){
				System.out.println("Yes");
			}
			else{
				System.out.println("No");
			}
		}
	}



	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}
