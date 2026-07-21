import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static class Wall{
		public int x;
		public int y;
		public int r;
		
		public Wall(int x, int y, int r) {
			super();
			this.x = x;
			this.y = y;
			this.r = r;
		}
	}
	
	public static final int SIZE = 10;
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		while(true){
			int n = sc.nextInt();
			if(n == 0){
				break;
			}
			
			List<Wall> w_list = new ArrayList<Wall>(n);
			for(int i = 0; i < n; i++){
				w_list.add(new Wall(sc.nextInt(), sc.nextInt(), sc.nextInt()));
			}
			
			int m = sc.nextInt();
			
			int[][] taros = new int[m][4];
			for(int i = 0; i < m; i++){
				for(int j = 0; j < 4; j++){
					taros[i][j] = sc.nextInt();
				}
			}
			
			for(int[] inputs : taros){
				List<Wall> use_list = new ArrayList<Wall>(n);
				use_list.addAll(w_list);
				
				int taro_x = inputs[0] , taro_y = inputs[1] ,oni_x = inputs[2] , oni_y = inputs[3];	
				
				int min_r = Integer.MAX_VALUE;
				Wall min_w = null;
				for(Wall w : use_list){
					if(((w.x - oni_x) * (w.x - oni_x) + (w.y - oni_y) * (w.y - oni_y)) < (w.r * w.r)){
						if(min_r > w.r){
							min_r = w.r;
							min_w = w;
						}
					}
				}
				
				boolean safe = false;
				
				if(min_r != Integer.MAX_VALUE){
					if(((min_w.x - taro_x) * (min_w.x - taro_x) + (min_w.y - taro_y) * (min_w.y - taro_y)) > (min_w.r * min_w.r)){
						safe = true;
					}
					
					if(safe){
						System.out.println("Safe");
						continue;
					}
					
					for(Iterator<Wall> ite = use_list.iterator(); ite.hasNext();){
						Wall w = ite.next();
						
						if(((min_w.x - w.x) * (min_w.x - w.x) + (min_w.y - w.y) * (min_w.y - w.y)) > (min_w.r * min_w.r)){
							ite.remove();
						}
					}
				}
				
				if(oni_x != taro_x){
					double a = (oni_y - taro_y) / (double)(oni_x - taro_x);
					double b = taro_y - a * taro_x;

					for (Wall w : use_list) {
						double c = w.x;
						double d = w.y;
						double r = w.r;

						double hantei = (a*a + 1)*r*r - d*d + (2*a*c + 2*b)*d - a*a*c*c - 2*a*b*c - b*b;
						//System.out.println(a + "," + b + "," + c + "," + d + "," + r + "," +  hantei);
						if (hantei >= 0) {
							double l_x,h_x;
							l_x = (-Math.sqrt(hantei) + a*d + c - a*b) / (a*a + 1);
							h_x = (Math.sqrt(hantei) + a*d + c - a*b) / (a*a + 1);
							//System.out.println(l_x + "," + h_x);
							
							if((Math.min(taro_x, oni_x) <= l_x && l_x <= Math.max(taro_x, oni_x)) || (Math.min(taro_x, oni_x) <= h_x && h_x <= Math.max(taro_x, oni_x))){
								safe = true;
								break;
							}
						}
					}
				}else{
					double a = oni_x;
					
					for (Wall w : use_list) {
						double c = w.x;
						double d = w.y;
						double r = w.r;

						double hantei = r*r - (a - c)*(a - c);
						//System.out.println(a + "," + c + "," + d + "," + r + "," +  hantei);
						if (hantei >= 0) {
							double l_y,h_y;
							l_y = d - Math.sqrt(hantei);
							h_y = d + Math.sqrt(hantei);
							//System.out.println(l_y + "," + h_y);
							
							if((Math.min(taro_y, oni_y) <= l_y && l_y <= Math.max(taro_y, oni_y)) || (Math.min(taro_y, oni_y) <= h_y && h_y <= Math.max(taro_y, oni_y))){
								safe = true;
								break;
							}
						}
					}
				}
				
				System.out.println(safe ? "Safe" : "Danger");
				
			}
			
		}
	}
	
}
