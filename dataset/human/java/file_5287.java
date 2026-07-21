import java.io.*;

class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			int width = Integer.parseInt(br.readLine());
			if(width == 0) return;
			
			int maxSize = 0;
			
			boolean[][] map = new boolean[width][width];
			
			int[] xy = new int[2];
			
			for(int y = 0; y < width; y++) {
				String str = br.readLine();
				for(int x = 0; x < width; x++) {
					if(str.charAt(x) == '*')
						map[y][x] = true;
					else {
						int nowSize = 1;
						
						sqCheck: for(int cWidth = 1; x - cWidth >= 0 && y - cWidth >= 0; cWidth++) {
							
							for(int cWidth2 = 0; cWidth2 <= cWidth; cWidth2++)
								if(map[y - cWidth + cWidth2][x - cWidth] || map[y - cWidth][x - cWidth + cWidth2])
									break sqCheck;
							
							nowSize++;
						}
						
						if(maxSize < nowSize) maxSize = nowSize;
					}
				}
			}
			System.out.println(maxSize);
		}
	}
	
	
}
