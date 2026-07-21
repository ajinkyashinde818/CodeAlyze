import std.stdio;
import std.math;
import std.algorithm;

double[100] bx, by, br;
int n, m;
double tx, ty, sx, sy;

void main(){
	while (readf("%d\n", &n), n) {
		foreach (i; 0..n) {
			readf("%s %s %s\n", &bx[i], &by[i], &br[i]);
		}

		readf("%d\n", &m);
		foreach (i; 0..m) {
			readf("%s %s %s %s\n", &tx, &ty, &sx, &sy);
			if (isSafe()) writeln("Safe");
			else writeln("Danger");
		}
	}
}

bool isSafe(){
	double relation;
	for (int i = 0; i < n; i++) {
		relation = inCircle(i, tx, ty) + inCircle(i, sx, sy);
		if (relation == 0) return true;
		if (br[i] >= perpendicular(i) && acuteAngle(i) && relation != 2) return true;
	}
	return false;
}

// in: 1, out: -1
int inCircle(int id, double x, double y){
	double dx = x - bx[id];
	double dy = y - by[id];
	if (br[id] > sqrt(dx*dx + dy*dy)) return 1;
	return -1;
}

// distance from line to point
double perpendicular(int id){
	double a, b, c;
	a = sy - ty;
	b = tx - sx;
	c = ty*sx - tx*sy;
	return abs(a*bx[id] + b*by[id] + c) / sqrt(a*a + b*b);
}

// inner product > 0 ?
bool acuteAngle(int id){
	double x1, x2, y1, y2;
	x1 = sx - tx;
	y1 = sy - ty;
	x2 = bx[id] - tx;
	y2 = by[id] - ty;
	if (x1*x2 + y1*y2 < 0) return false;
	x1 = -x1;
	y1 = -y1;
	x2 = bx[id] - sx;
	y2 = by[id] - sy;
	if (x1*x2 + y1*y2 < 0) return false;
	return true;
}
