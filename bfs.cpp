#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
};

char map[20][20] = 
{
	".#...#.#",
	".#.#....",
	"...#..#.",
	"...#..#.",	
};

Node steps[] = 
{
	{-1, 0}, // up
	{0,  1}, // right
	{1,  0}, // down
	{-1, 0}  // left
};

queue<Node> q;
int book[20][20];

void around(Node n)
{
	int i, s;
	Node c;
	
	s = book[n.x][n.y];
	printf("into s %2d %d,%d\n", s, n.x, n.y);
	
	for (i=0; i<sizeof(steps)/sizeof(Node); i++) {
		c.x = n.x + steps[i].x;
		c.y = n.y + steps[i].y;
		
		if(c.x < 0 || c.y < 0 || map[c.x][c.y]==0)
			continue;
		if(book[c.x][c.y])
			continue;
		if(map[c.x][c.y] == '#') {
			book[c.x][c.y] = -1;
			continue;
		}

		book[c.x][c.y] = s+1;
		q.push(c);
	}
}

int main(void) 
{
	int i, j;
	Node n;
	
	for(i=0; i<20; i++) {
		for(j=0;j<20;j++)
			if(map[i][j]) cout << map[i][j];
		cout << endl;
		if (!map[i][j]) break;
	}
	
	n.x=0;
	n.y=0;
	book[n.x][n.y] = 1;
	q.push(n);
	
	while(!q.empty()) {
		around(q.front());
		q.pop();
	}
	
	for(i=0; i<20; i++) {
		for(j=0;j<20;j++)
			if(book[i][j])
				printf("%2d ", book[i][j]);
		cout << endl;
		if (!book[i][j]) break;
	}
	
	return 0;
}
