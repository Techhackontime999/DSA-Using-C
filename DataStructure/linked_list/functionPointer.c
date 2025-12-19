#include<stdio.h>
void say(char *str){
printf("Hello %s\n",str);
}
void fun(void (*ptr)(char *)){
// (*ptr)("suraj");
ptr("suraj");

}
int main(){
// void (*ptr)(char *)=say;
// (*ptr)("suraj");
// ptr("suraj");
// say("suraj");
// fun(say);

void (*ptr)(char *);
ptr=say;
ptr("suraj");

    return 0;
}