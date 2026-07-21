#include <stdio.h>
#include <math.h>

/*
niten wo tooru chokusen no motomekata

x1+b*y1+c=0
x2+b*y2+c=0

y1 1 | b | -x1
y2 1 | c | -x2

1/(y1-y2) *
  1  -1 | -x1
-y2  y1 | -x2

b = (x2-x1)/(y1-y2)
c = (x1*y2-x2*y1)/(y1-y2)

(y1-y2)*x + (x2-x1)*y + (x1*y2-x2*y1) = 0

*/

typedef struct {
	int valid_num;
	double x1,y1,x2,y2;
} data_t;

data_t num_data(double v) {
	data_t d;
	d.valid_num=1;
	d.x1=v;
	return d;
}

data_t num_num(data_t n1,data_t n2) {
	data_t d;
	d.valid_num=2;
	d.x1=n1.x1;
	d.y1=n2.x1;
	return d;
}

data_t point_point(data_t p1,data_t p2) {
	data_t d;
	d.valid_num=4;
	d.x1=p1.x1;
	d.y1=p1.y1;
	d.x2=p2.x1;
	d.y2=p2.y1;
	return d;
}

data_t point_line(data_t p,data_t l) {
	double xx=l.y2-l.y1;
	double yy=l.x1-l.x2;
	double d=sqrt(xx*xx+yy*yy);
	double a=l.y1-l.y2;
	double b=l.x2-l.x1;
	double c=l.x1*l.y2-l.x2*l.y1;
	double dist=fabs(a*p.x1+b*p.y1+c)/sqrt(a*a+b*b);
	double cx1=p.x1+2.0*xx*dist/d;
	double cy1=p.y1+2.0*yy*dist/d;
	double cx2=p.x1-2.0*xx*dist/d;
	double cy2=p.y1-2.0*yy*dist/d;
	double dist1=fabs(a*cx1+b*cy1+c)/sqrt(a*a+b*b);
	double dist2=fabs(a*cx2+b*cy2+c)/sqrt(a*a+b*b);
	data_t ret;
	ret.valid_num=2;
	/* hantai ni ittara kyori ga dekakunaru */
	if(dist1<dist2) {
		ret.x1=cx1;
		ret.y1=cy1;
	} else {
		ret.x1=cx2;
		ret.y1=cy2;
	}
	return ret;
}

data_t line_line(data_t l1,data_t l2) {
	double a1=l1.y1-l1.y2;
	double b1=l1.x2-l1.x1;
	double mc1=-(l1.x1*l1.y2-l1.x2*l1.y1);
	double a2=l2.y1-l2.y2;
	double b2=l2.x2-l2.x1;
	double mc2=-(l2.x1*l2.y2-l2.x2*l2.y1);
	double d=a1*b2-b1*a2;
	data_t ret;
	ret.valid_num=2;
	ret.x1=(b2*mc1-b1*mc2)/d;
	ret.y1=(-a2*mc1+a1*mc2)/d;
	return ret;
}

data_t error_data(void) {
	data_t ret;
	ret.valid_num=0;
	return ret;
}

data_t operator_data(void) {
	data_t ret;
	ret.valid_num=-1;
	return ret;
}

data_t kakko_data(void) {
	data_t ret;
	ret.valid_num=-2;
	return ret;
}

data_t calc(data_t a,data_t b) {
	switch(a.valid_num) {
		case 1:
			switch(b.valid_num) {
				case 1: return num_num(a,b);
			}
			break;
		case 2:
			switch(b.valid_num) {
				case 2: return point_point(a,b);
				case 4: return point_line(a,b);
			}
			break;
		case 4:
			switch(b.valid_num) {
				case 2: return point_line(b,a);
				case 4: return line_line(a,b);
			}
			break;
	}
	return error_data();
}

int siki_num;
data_t siki[1000];
int stack_num;
data_t stack[1000];

void compile(const char *expr) {
	double current_value=-1;
	int current_sign=1;
	siki_num=0;
	stack_num=0;
	for(;*expr!='\0';expr++) {
		if('0'<=*expr && *expr<='9') {
			if(current_value<0)current_value=0;
			current_value=current_value*10+(*expr-'0');
		} else {
			if(current_value>-0.5) {
				siki[siki_num++]=num_data(current_value*current_sign);
				current_value=-1;
				current_sign=1;
			}
			if(*expr=='(') {
				stack[stack_num++]=kakko_data();
			} else if(*expr==')') {
				while(stack_num>0 && stack[--stack_num].valid_num!=-2) {
					siki[siki_num++]=stack[stack_num];
				}
			} else if(*expr=='-') {
				current_sign=-1;
			} else if(*expr==',' || *expr=='@') {
				while(stack_num>0 && stack[stack_num-1].valid_num!=-2) {
					siki[siki_num++]=stack[--stack_num];
				}
				stack[stack_num++]=operator_data();
			}
		}
	}
	if(current_value>-0.5) {
		siki[siki_num++]=num_data(current_value*current_sign);
		current_value=-1;
		current_sign=1;
	}
	while(stack_num>0) {
		siki[siki_num++]=stack[--stack_num];
	}
}

data_t run(void) {
	int i;
	stack_num=0;
	for(i=0;i<siki_num;i++) {
		if(siki[i].valid_num<=0) {
			if(stack_num<2)return error_data();
			stack[stack_num-2]=calc(stack[stack_num-2],stack[stack_num-1]);
			stack_num--;
		} else {
			stack[stack_num++]=siki[i];
		}
	}
	return stack[0];
}

int main(void) {
	char input[1024];
	while(scanf("%s",input)==1 && input[0]!='#') {
		data_t res;
		compile(input);
		res=run();
		printf("%.15f %.15f\n",res.x1,res.y1);
	}
	return 0;
}
