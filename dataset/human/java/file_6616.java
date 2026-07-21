import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
//		String[] tmpArray = br.readLine().split(" ");
		
		String command = br.readLine();
		
		String[] tmpArray = br.readLine().split(" ");
		
		int destX = Integer.parseInt(tmpArray[0]);
		int destY = Integer.parseInt(tmpArray[1]);
		
		String f[] = command.split("T", -1);
		int dist[] = new int[f.length];
		
		for(int i = 0; i < f.length; i++){
			dist[i] = f[i].length();
			
			//debug
//			System.out.print(dist[i] + " ");
		}
		
//		System.out.println();
		
//		int currentX = 0;
//		int currentY = 0;
//		int x = destX;
//		int y = Math.abs(destY);

		//座標は8000を原点とする
		boolean dpx[][] = new boolean[dist.length][16001];
		boolean dpy[][] = new boolean[dist.length][16001];

		dpx[0][8000+dist[0]] = true;
		if(dist.length >= 2){
			dpy[1][8000+dist[1]] = true;
			dpy[1][8000-dist[1]] = true;
		}
		int lastX = 0;
		int lastY = 1;

		for(int i = 2; i < dist.length ; i++){
			//横移動
			if(i % 2 == 0){
				lastX = i;
				for(int j = 0; j < dpx[0].length ; j++){
					if(j >= dist[i] && dpx[i - 2][j - dist[i]]){
						dpx[i][j] = true;
//						System.out.println("x "+(j - 8000)+" is ok at i = "+i);
					}
					if(j < dpx[0].length - dist[i] && dpx[i - 2][j + dist[i]]){
						dpx[i][j] = true;
//						System.out.println("x "+(j - 8000)+" is ok at i = "+i);
					}

					//					if(i != 0){
					//						x = Math.abs(x);
					//					}
					//					currentX += dist[i];
					//
					//					if(currentX > x){
					//						x = currentX + (currentX - x);
					//					}
				}

			}
			//縦移動
			else {
				lastY = i;
				for(int j = 0; j < dpx[0].length ; j++){
					if(j >= dist[i] && dpy[i - 2][j - dist[i]]){
						dpy[i][j] = true;
//						System.out.println("y "+(j - 8000)+" is ok at i = "+i);
					}
					if(j < dpx[0].length - dist[i] && dpy[i - 2][j + dist[i]]){
						dpy[i][j] = true;
//						System.out.println("y "+(j - 8000)+" is ok at i = "+i);
					}
				}
//				for(int j = 0; j < dpx[0].length ; j++){
//					currentY += dist[i];
//
//					if(currentY > y){
//						y = currentY + (currentY - y);
//					}
//				}
			}

		
			//debug
//			System.out.println("current; "+currentX+","+currentY);
//			System.out.println("next dest; "+x+","+y);
		}
		
//		if(x == currentX && y == currentY){
		if(dpx[lastX][destX+8000] && ((dist.length <= 1 && destY == 0) || dpy[lastY][destY+8000])){
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}

}
