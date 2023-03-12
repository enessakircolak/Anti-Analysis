#include<stdio.h>

void before() {
	printf("isiklari kapatma patron\n");

}
void before_main() __attribute__((constructor));
void after_main() __attribute__((destructor));
void before_main() {
	before();
   printf("This is executed before main.");
}
void after_main() {
   printf("This is executed after main.");
}



main() {
   printf("Inside main");
}

