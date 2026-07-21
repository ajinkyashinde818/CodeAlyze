import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;


public class Main {
	
	public static final int NONE = Integer.MAX_VALUE;
	public static final int EAST = 0;
	public static final int NORTH = 1;
	public static final int WEST = 2;
	public static final int SOUTH = 3;
	
	public static final int[][] look = new int[][]{
		{1, 0}, {0, -1}, {-1, 0}, {0, 1}
	};
	
	public static final int[][][] move = new int[][][]{
		{{0, 1}, {1, 0}, {0, -1}, {-1, 0}},
		{{1, 0}, {0, -1}, {-1, 0}, {0, 1}},
		{{0, -1}, {-1, 0}, {0, 1}, {1, 0}},
		{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
	};
		
	public static final int[][] move_dir = new int[][]{
		{SOUTH, EAST, NORTH, WEST},
		{EAST, NORTH, WEST, SOUTH},
		{NORTH, WEST, SOUTH, EAST},
		{WEST, SOUTH, EAST, NORTH}
	};
	
	public static final int WALL = 0;
	public static final int FLAT = 1;
	public static final int EXIT = 2;
	
	public static boolean is_ok(int x, int y, int h, int w){
		if(x < 0 || x >= w || y < 0 || y >= h){
			return false;
		}else{
			return true;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			final int W = sc.nextInt();
			final int H = sc.nextInt();
			
			if(W == 0 && H == 0){
				break;
			}
			
			int map[][] = new int[H][W];
			int people[][] = new int[H][W];
			int next_people[][] = new int[H][W];
			
			for(int i = 0; i < H; i++){
				char[] input = sc.next().toCharArray();
				
				for(int j = 0; j < W; j++){
					switch(input[j]){
					case '#':
						map[i][j] = WALL;
						people[i][j] = NONE;
						break;
					case '.':
						map[i][j] = FLAT;
						people[i][j] = NONE;
						break;
					case 'X':
						map[i][j] = EXIT;
						people[i][j] = NONE;
						break;
					case 'E':
						people[i][j] = EAST;
						map[i][j] = FLAT;
						break;
					case 'W':
						people[i][j] = WEST;
						map[i][j] = FLAT;
						break;
					case 'N':
						people[i][j] = NORTH;
						map[i][j] = FLAT;
						break;
					case 'S':
						people[i][j] = SOUTH;
						map[i][j] = FLAT;
						break;	
					}
				}
			}
			
			boolean over = true;
			int end_time = 1;
			for(int time = 1; time <= 180; time++){
				//change_look
				for(int i = 0; i < H; i++){
					for(int j = 0; j < W; j++){
						if(people[i][j] != NONE){
							final int dir = people[i][j];
							
							for(int looking : move_dir[dir]){
								int[] move_d = look[looking];
								
								final int nx = j + move_d[0];
								final int ny = i + move_d[1];
								
								if(!is_ok(nx, ny, H, W)){
									continue;
								}else if(map[ny][nx] == WALL){
									continue;
								}else if(people[ny][nx] != NONE){
									continue;
								}
								
								people[i][j] = looking;
								break;
							}
						}
					}
				}
				
				//move
				for(int i = 0; i < H; i++){
					for(int j = 0; j < W; j++){
						if(map[i][j] == WALL){
							continue;
						}else if(people[i][j] != NONE){
							continue;
						}
						
						boolean flag = false;
						for(int dir : move_dir[NORTH]){
							int[] looking = look[dir];
							final int ref = (4 + dir - 2) % 4;
							
							final int nx = j + looking[0];
							final int ny = i + looking[1];
							
							if(!is_ok(nx, ny, H, W)){
								continue;
							}else if(map[ny][nx] == WALL){
								continue;
							}else if(people[ny][nx] == NONE){
								continue;
							}else if(people[ny][nx] != ref){
								continue;
							}
							
							next_people[i][j] = people[ny][nx];
							next_people[ny][nx] = NONE;
							flag = true;
							break;
						}
						
						if(!flag){
							next_people[i][j] = people[i][j];
						}
					}
				}
				
				//remove
				for(int i = 0; i < H; i++){
					for(int j = 0; j < W; j++){
						if(map[i][j] != EXIT){
							continue;
						}else if(next_people[i][j] == NONE){
							continue;
						}
						
						next_people[i][j] = NONE;
					}
				}
				
				//is_end?
				boolean is_end = true;
				//remove
				END:
				for(int i = 0; i < H; i++){
					for(int j = 0; j < W; j++){
						if(map[i][j] == WALL){
							continue;
						}else if(next_people[i][j] == NONE){
							continue;
						}
						
						is_end = false;
						break END;
					}
				}
				
				if(is_end){
					over = false;
					end_time = time;
					break;
				}
				
				//update
				for(int i = 0; i < H; i++){
					for(int j = 0; j < W; j++){
						people[i][j] = next_people[i][j];
					}
				}
			}
			
			if(over){
				System.out.println("NA"); 
			}else{
				System.out.println(end_time);
			}
		}
		
	}

}
