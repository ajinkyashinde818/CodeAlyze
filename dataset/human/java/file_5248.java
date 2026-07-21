import java.util.*;

class Main {
	Scanner sc = new Scanner(System.in);

	public void run() {
		while(true){
			int n=sc.nextInt();
			if(n==0)break;
			char[][] map=new char[n][n];
			for(int i=0;i<n;i++){
				map[i]=sc.next().toCharArray();
			}
			int max=0;
			for(int y=0;y<n;y++)
				for(int x=0;x<n;x++){
					int w=0,h=0;
					while(x+w<n && map[y][x+w]!='*')w++;
					while(y+h<n && map[y+h][x]!='*')h++;
					for(int dy=0;dy<h;dy++)for(int dx=0;dx<w;dx++){
						if(y+dy<n && x+dy<n && map[y+dy][x+dx]=='*'){
							if(dx<dy){
								h=dy;
							}else if(dx>dy){
								w=dx;
							}else{
								h=w=dx;
							}
						}
					}
					max=Math.max(max,Math.min(w,h));
				}

			ln(max);
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}

	public static void pr(Object o) {
		System.out.print(o);
	}

	public static void ln(Object o) {
		System.out.println(o);
	}

	public static void ln() {
		System.out.println();
	}
}
