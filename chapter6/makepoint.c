#include <stdio.h>
#define XMAX 1080


struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};


struct point makepoint(int x, int y){
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}


struct rect screen;
struct point middle;
struct point makepoint(int, int);


/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2){
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}


/* printrect: return 1 if p in r, 0 if not */
int printrect(struct point p, struct point r){
	return p.x >= r.pt1.x && p.x < r.pt2.x
			&& p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main(int argc, char *argv[]){

	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(xmax, xmax);
	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
		(screen.pt1.y + screen.pt2.y) / 2);
}
