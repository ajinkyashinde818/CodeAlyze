import java.util.Scanner;
import java.util.ArrayList;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		int x =sc.nextInt();
		int y =sc.nextInt();
		ArrayList<Integer> xlist=new ArrayList<>();
		ArrayList<Integer> ylist=new ArrayList<>();
		int count=0;
		boolean isX=true;
		for(int i=0; i<s.length(); i++){
			if(s.charAt(i)=='T'){
				if(isX){
					xlist.add(count);
				}else{
					ylist.add(count);
				}
				isX=!isX;
				count=0;
			}else{
				count++;
			}
		}
		if(isX){
			xlist.add(count);
		}else{
			ylist.add(count);
		}
		int sumx=0;
		boolean[][] dpx=new boolean[xlist.size()][16000];
		boolean[][] dpy=new boolean[ylist.size()+1][16001];
		int nx=0;
		int ny=1;
		for(int i:xlist){
			if(nx==0){
				sumx+=i;
				dpx[nx][sumx+7999]=true;
				nx++;
				continue;
			}
			for(int j=-sumx; j<=sumx; j++){
				if(dpx[nx-1][j+7999]){
					dpx[nx][j+7999+i]=true;
					dpx[nx][j+7999-i]=true;
				}
			}
			nx++;
			sumx+=i;
		}
		int sumy=0;
		dpy[0][8000]=true;
		for(int i:ylist){
			for(int j=-sumy; j<=sumy; j++){
				if(dpy[ny-1][j+8000]){
					dpy[ny][j+8000+i]=true;
					dpy[ny][j+8000-i]=true;
				}
			}
			ny++;
			sumy+=i;
		}
		if(x==-8000){
			System.out.println("No");
			return;
		}
		if(dpx[xlist.size()-1][7999+x] && dpy[ylist.size()][8000+y]){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
