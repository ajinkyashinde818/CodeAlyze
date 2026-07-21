import java.util.Scanner;


public class Main{
	static int[] depth;
	static int[] leftChild;
	static int[] rightChild;
	static int[] parent;
	static String[] type;
	static int[] height;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int cnt = new Integer(s.nextLine()).intValue();
		parent = new int[cnt];
		leftChild = new int[cnt];
		rightChild = new int[cnt];
		int[] sibling = new int[cnt];
		int[] degrees = new int[cnt];
		type = new String[cnt];
		depth = new int[cnt];
		height = new int[cnt];
		for(int a=0 ; a<cnt ; a++) {
			parent[a] = -1;
			leftChild[a] = -1;
			rightChild[a] = -1;
			sibling[a] = -1;
			degrees[a] = 0;
			depth[a] = 0;
			type[a] = "root";
			height[a] = 0;
		}
		int root = -1;
		for(int i=0 ; i<cnt ; i++) {
			String[] tmp = s.nextLine().split(" ");
			int degree = 0;
			leftChild[new Integer(tmp[0]).intValue()] = new Integer(tmp[1]).intValue();
			rightChild[new Integer(tmp[0]).intValue()] = new Integer(tmp[2]).intValue();
			if(new Integer(tmp[1]).intValue()!=-1){
				parent[new Integer(tmp[1]).intValue()] = new Integer(tmp[0]).intValue();
				degree++;
			}
			if(new Integer(tmp[2]).intValue()!=-1) {
				parent[new Integer(tmp[2]).intValue()] = new Integer(tmp[0]).intValue();
				degree++;
			}
			degrees[new Integer(tmp[0]).intValue()] = degree;
			if(new Integer(tmp[1]).intValue()!=-1 && new Integer(tmp[2]).intValue()!=-1) {
				sibling[new Integer(tmp[1]).intValue()] = new Integer(tmp[2]).intValue();
				sibling[new Integer(tmp[2]).intValue()] = new Integer(tmp[1]).intValue();
			}

			for(int j=0 ; j<parent.length ; j++) {
				if(parent[j] == -1) {
					root = j;
					break;
				}
			}
		}
		setDepth(root, 0);
		setType();
		for(int i=0 ; i<leftChild.length ; i++) {
			height[i] = setHeight(i, 0);
		}

		for(int k=0 ; k<cnt ; k++) {
			System.out.println("node " + k + ": parent = " + parent[k] + ", sibling = " + sibling[k] + ", degree = " + degrees[k] + ", depth = " + depth[k] + ", height = " + height[k] + ", "+ type[k]);
		}
	}

	public static void setDepth(int val, int d) {
		depth[val] = d;
		if(rightChild[val] != -1)
			setDepth(rightChild[val], d+1);
		if(leftChild[val] != -1)
			setDepth(leftChild[val], d+1);
	}

	public static void setType() {
		for(int i=0 ; i<leftChild.length ; i++) {
			if(parent[i] == -1) {}
			else if(leftChild[i] == -1 && rightChild[i] == -1)
				type[i] ="leaf";//leaf
			else
				type[i] = "internal node";//internal node
		}
	}

	public static int setHeight(int val, int height) {
		if(val==-1)
			return height;
		if(leftChild[val]==-1 && rightChild[val]==-1)
			return height;
		return Math.max(setHeight(leftChild[val], height+1), setHeight(rightChild[val], height+1));
	}
}
