import java.util.ArrayList;
import java.util.Scanner;

class Pair{
	int x;
	int y;
	public Pair(int x, int y) {
		super();
		this.x = x;
		this.y = y;
	}
	@Override
	public String toString() {
		return "Pair [x=" + x + ", y=" + y + "]";
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	
}

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		boolean flag=false;
		ArrayList<Pair> a=new ArrayList<Pair>();
		for(int i=0;i<n;i++) {
			a.add(new Pair(sc.nextInt(),sc.nextInt()));
		}
		boolean ans=false;
		for(int i=0;i<n-2;i++) {
			if(a.get(i).x==a.get(i).y) {
				if(a.get(i+1).x==a.get(i+1).y&&a.get(i+2).x==a.get(i+2).y) {
					ans=true;
					break;
				}
			}
		}
		
		if(ans==true) System.out.println("Yes");
		else System.out.println("No");
	}

}
