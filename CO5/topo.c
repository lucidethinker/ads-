#include <stdio.h>

void main() {
  int n = 0;
  printf("enter how many vertex are there - ");
  scanf("%d", & n);
  int a[n][n], tp[n], f[n], x = 0;

  //considering the vertices to be numbers
  printf("\nEnter 1 if an edge exits or otherwise\n");
  for (int i = 1; i <= n; i++) {
    f[i - 1] = 0;
    for (int j = 1; j <= n; j++) {
      printf("Does an edge exists from %d to %d - ", i, j);
      scanf("%d", & a[i - 1][j - 1]);
    }
  }
  while (x < n) {
    //finding indegree of all vertices
    int in = 0, ind[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[j][i] == 1) {
          in ++;
        }
      }
      ind[i] = in ; in = 0;
    }
    //Actual sorting
    int t = 0;
    for (t = 0; t < n; t++) {
      if (ind[t] == 0 && f[t] == 0) {
        f[t] = 1;
        printf("%d ", t + 1);
        break;
      }
    }
    printf("\n");
    //updating matrix with new values
    for (int i = 0; i < n; i++) {
      if (a[t][i] == 1) {
        a[t][i] = 0;
      }
    }
    x++;
  }
}