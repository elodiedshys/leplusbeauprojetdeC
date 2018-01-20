#include <stdio.h>

void affichePlateau() {
  int i, j, k;
  j=0;

  for(i=0;i<19;i++){
    if(i<10){
      printf("  %d  ",i );
    }
    else if(i==18){
      printf("%d\n",j );
      j++;
    }
    else{
      printf(" %d ",i);
    }
  }
}

int main(int argc, char const *argv[])
{
  affichePlateau();
  return 0;
}