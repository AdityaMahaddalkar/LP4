#include <stdio.h>

int main(){
  int x = 900;
  printf("X = %d\n", x);

  if(x == 1000){
    printf("Something's wrong, I can feel it\n");
  }
  else{
    printf("Baby Yoda should not be the meme of the decade!!!!\n");
  }

  for(int i = 0;i < 100;i ++){
    printf("i = %d\n", i);
  }
  return 0;
}

void helloWorld(int s, float operator, char id){
  printf("%d %f %c", s, operator, id);
}
