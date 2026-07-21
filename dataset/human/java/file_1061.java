import java.util.*;
import java.io.*;

public class Main {
	
	public double dist(Point a, Point b){
		return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	}
	public double dist(Point a, Circle b){
		return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	}
	public boolean judge(Circle wall, Point a, Point b){
		if( (Math.hypot(a.x-wall.x, a.y-wall.y)-wall.r)*(Math.hypot(b.x-wall.x, b.y-wall.y)-wall.r) < 0 ){
			return true;
		} else if( Math.hypot(a.x-wall.x, a.y-wall.y)-wall.r < 0 ){
			return false;
		}
		double t = (double)-1*((a.x-wall.x)*(b.x-a.x)+(a.y-wall.y)*(b.y-a.y)) / dist(a, b);
		double p = a.x - wall.x + t*(b.x-a.x);
		double q = a.y - wall.y + t*(b.y-a.y);
		if( p*p + q*q <= wall.r*wall.r ){
			double key = Math.max(dist(a, wall)-wall.r*wall.r, dist(b, wall)-wall.r*wall.r);
			if( dist(a, b) - key >= 0 ){
				return true;
			}
		}
		return false;
	}		
	public void solve() throws IOException{
		int n;
		while( (n = nextInt()) != 0 ){
			Circle[] wall = new Circle[n];
			for(int i = 0; i < n; i++){
				int x = nextInt(), y = nextInt(), r = nextInt();
				wall[i] = new Circle(x, y, r);
			}
			int m = nextInt();
		
		out:for(int i = 0; i < m; i++){
				int x = nextInt(), y = nextInt(), w = nextInt(), z = nextInt();
				Point hide = new Point(x, y);
				Point seek = new Point(w, z);
				for(int j = 0; j < n; j++){
					if( judge(wall[j], hide, seek) ){
						writer.println("Safe");
						continue out;
					}
				}
				writer.println("Danger");
			}			
		}
		writer.flush();
	}		
	public static void main (String args[]) throws IOException{
		new Main().run();
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	
	public void run() throws IOException{
		try{
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e){
			e.printStackTrace();
			System.exit(1);
		}
	}
	public int nextInt() throws IOException{
		return Integer.parseInt(nextToken());
	}
	public String nextToken() throws IOException{
		while( tokenizer == null || !tokenizer.hasMoreTokens() ){
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}

class Circle {
	int x;
	int y;
	int r;
	Circle(int x, int y, int r){
		this.x = x;
		this.y = y;
		this.r = r;
	}
	public String toString(){
		return x + " " + y + " " + r;
	}
}

class Point {
	int x;
	int y;
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	public String toString(){
		return x + " " + y;
	}
}
