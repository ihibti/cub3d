#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  int res = c + b + a;
  if (n <= 4)
    {
        return res;
    }
    return (find_nth_term(n -1,b ,c,res));
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("res  = %d\n", ans); 
    return 0;
}

