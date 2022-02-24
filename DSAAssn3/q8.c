#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 10000
typedef struct{
  float x;
  float y;
} vertex;
float max(float x, float y){
  if (x>y) {
    return x;
  }
  else return y;
}
float min(float x, float y){
  if (x<y) {
    return x;
  }
  else return y;
}
bool onSegment(vertex p, vertex q, vertex r){
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}
int orientation(vertex p, vertex q, vertex r){
	int val = (q.y - p.y) * (r.x - q.x) -	(q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0; // collinear
	 return (val > 0)? 1: 2; // clock or counterclock wise
}
bool doIntersect(vertex p1, vertex q1, vertex p2, vertex q2){
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4)
		return true;
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false;
}
bool check_inside(vertex v1[], vertex v2, int n){
  if (n < 3) return false;
  vertex extreme = {INF, v2.y};
  int count = 0, i = 0;
  do{
    int next = (i+1)%n;
    if (doIntersect(v1[i], v1[next], v2, extreme)){
      if (orientation(v1[i], v2, v1[next]) == 0)
        return onSegment(v1[i], v2, v1[next]);
      count++;
    }
    i = next;
  } while (i != 0);
  return count&1;
}
int main() {
  int count=0, temp[5][2], k=0, l=0;
  vertex p1[5], p2[5];
  for (int k=0; k < 5; k++){
      printf("xa[%d], ya[%d]:", k, k);
      scanf(" %f %f", &p1[k].x, &p1[k].y);
  }
  for (int k=0; k < 5; k++){
      printf("xb[%d], yb[%d]:", k, k);
      scanf(" %f %f", &p2[k].x, &p2[k].y);
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (p1[i].x == p2[j].x && p1[i].y == p2[j].y) {
        count++;                           //counting all equal vertices
        temp[k][0] = i;
        temp[k][1] = j;
        k++;
        break;
      }
    }
  }
  if (count == 5) {
    printf("They are equal pentagons\n");
  } else if (count == 4) {
    if (check_inside(p1, p2[temp[0][1]], 5)) {
      printf("Pentagon 2 is inside pentagon 1\n");
    } else {
      printf("Pentagon 1 is inside pentagon 2\n");
    }
  } else if(count == 3){
    if ((check_inside(p1, p2[temp[0][1]], 5) && check_inside(p1, p2[temp[1][1]], 5))
        || (check_inside(p2, p1[temp[0][0]], 5) && check_inside(p2, p1[temp[1][0]], 5))) {
      printf("One pentagon is inside the other!!\n");
    }else if((!check_inside(p1, p2[temp[0][1]], 5) && !check_inside(p1, p2[temp[1][1]], 5) && !check_inside(p1, p2[temp[2][1]], 5) && !check_inside(p1, p2[temp[3][1]], 5))
        && (!check_inside(p2, p1[temp[0][0]], 5) && !check_inside(p2, p1[temp[1][0]], 5) && !check_inside(p2, p1[temp[2][0]], 5) && !check_inside(p2, p1[temp[3][0]], 5))){
      printf("The polygons touch each other at one vertex\n");
    }
    else {
      printf("Intersecting pentagons!!\n");
    }
  }else if(count == 2){
    if ((check_inside(p1, p2[temp[0][1]], 5) && check_inside(p1, p2[temp[1][1]], 5) && check_inside(p1, p2[temp[2][1]], 5))
        || (check_inside(p2, p1[temp[0][0]], 5) && check_inside(p2, p1[temp[1][0]], 5) && check_inside(p2, p1[temp[2][0]], 5))) {
      printf("One pentagon is inside the other!!\n");
    }else if((!check_inside(p1, p2[temp[0][1]], 5) && !check_inside(p1, p2[temp[1][1]], 5) && !check_inside(p1, p2[temp[2][1]], 5))
        && (!check_inside(p2, p1[temp[0][0]], 5) && !check_inside(p2, p1[temp[1][0]], 5) && !check_inside(p2, p1[temp[2][0]], 5))){
      printf("The polygons touch each other at one side\n");
    }
    else {
      printf("Intersecting pentagons!!\n");
    }
  }else if(count == 1){
    if ((check_inside(p1, p2[temp[0][1]], 5) && check_inside(p1, p2[temp[1][1]], 5) && check_inside(p1, p2[temp[2][1]], 5) && check_inside(p1, p2[temp[3][1]], 5))
        || (check_inside(p2, p1[temp[0][0]], 5) && check_inside(p2, p1[temp[1][0]], 5) && check_inside(p2, p1[temp[2][0]], 5) && check_inside(p2, p1[temp[3][0]], 5))) {
      printf("One pentagon is inside the other!!\n");
    }else if((!check_inside(p1, p2[temp[0][1]], 5) && !check_inside(p1, p2[temp[1][1]], 5) && !check_inside(p1, p2[temp[2][1]], 5) && !check_inside(p1, p2[temp[3][1]], 5))
        && (!check_inside(p2, p1[temp[0][0]], 5) && !check_inside(p2, p1[temp[1][0]], 5) && !check_inside(p2, p1[temp[2][0]], 5) && !check_inside(p2, p1[temp[3][0]], 5))){
      printf("The polygons touch each other at one vertex\n");
    }
    else {
      printf("Intersecting pentagons!!\n");
    }
  }else if(count == 0){
    if ((check_inside(p1, p2[temp[0][1]], 5) && check_inside(p1, p2[temp[1][1]], 5) && check_inside(p1, p2[temp[2][1]], 5) && check_inside(p1, p2[temp[3][1]], 5) && check_inside(p1, p2[temp[4][1]], 5))
        || (check_inside(p2, p1[temp[0][0]], 5) && check_inside(p2, p1[temp[1][0]], 5) && check_inside(p2, p1[temp[2][0]], 5) && check_inside(p2, p1[temp[3][0]], 5) && check_inside(p2, p1[temp[4][0]], 5))) {
      printf("One pentagon is inside the other!!\n");
    }else if((!check_inside(p1, p2[temp[0][1]], 5) && !check_inside(p1, p2[temp[1][1]], 5) && !check_inside(p1, p2[temp[2][1]], 5) && !check_inside(p1, p2[temp[3][1]], 5) && !check_inside(p1, p2[temp[4][1]], 5))
        && (!check_inside(p2, p1[temp[0][0]], 5) && !check_inside(p2, p1[temp[1][0]], 5) && !check_inside(p2, p1[temp[2][0]], 5) && !check_inside(p2, p1[temp[3][0]], 5) && !check_inside(p2, p1[temp[4][0]], 5))){
      printf("Non intersecting pentagons!!\n");
    }else if(onSegment(p1[0], p2[0], p2[0])){
      printf("One pentagon touches the side of another\n");
    }
    else {
      printf("Intersecting pentagons!!\n");
    }
  }
  return 0;
}
