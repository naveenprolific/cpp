#include "stdio.h"
#define LEFT 0
#define RIGHT 1
int v[16], d[16];
void swap(int i, int j)
{
 int tmp;
 tmp = v[i];
 v[i] = v[j];
 v[j] = tmp;
 tmp = d[i];
 d[i] = d[j];
 d[j] = tmp;
}
void print_p(int n)
{
 int i;
 for (i = 0; i < n; i++)
 printf("%d ", v[i]);
 printf("\n");
}
int sjtSwap(int n, int start)
{
 int i, j;
 int k = -1, dir, s;
 static int sjtCount = 0;
 for (i = start; i < n + start; i++) {
 if (d[i] == LEFT && i > start + 0) {
 if (v[i] > v[i - 1]) {
 if (v[i] > k) {
 k = v[i];
 s = i;
 dir = LEFT;
 }
 }
 } else if (d[i] == RIGHT && i < start + n - 1) {
 if (v[i] > v[i + 1]) {
 if (v[i] > k) {
 k = v[i];
 s = i;
 dir = RIGHT;
 }
 }
 }
 }
 if (k == -1)
 return k;
 if (dir == LEFT) {
 swap(s, s - 1);
 } else {
 swap(s, s + 1);
 }
 // printf("%3d ", s * (dir ? 1 : -1));
 sjtCount++;
 if (sjtCount == 2 * n) { 
 // printf("\n");
 sjtCount = 0;
 }
 for (i = start; i < start + n; i++) {
 if (v[i] <= k)
 continue;
 else
 d[i] = (d[i] + 1) % 2; // change direction
 }
 return k;
}
void main(int argc, char *argv[])
{
 int n = atoi(argv[1]);
 int i, cnt, k;
 for (i = 0; i < n; i++) {
 v[i] = i + 1;
 d[i] = LEFT;
 }
 print_p(n);
 cnt = 1;
 while (1) {
 // generate n permutations travelling left with n moving
 for (i = n - 1; i > 0; i--) {
 swap(i, i - 1);
 cnt++;
 print_p(n);
 }
 // change direction
 k = sjtSwap(n - 1, 1);
 if (k == -1) {
 printf("\nperms = %d\n", cnt);
 return;
 }
 cnt++; 
 print_p(n);
 // generate n permutations travelling right with n moving
 for (i = 0; i < n - 1; i++) {
 swap(i, i + 1);
 print_p(n);
 cnt++;
 }
 // change direction
 k = sjtSwap(n - 1, 0);
 if (k == -1) {
 printf("\nperms = %d\n", cnt);
 return;
 }
 cnt++;
 print_p(n);
 }
}
