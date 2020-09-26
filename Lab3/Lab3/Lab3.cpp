#include <stdio.h>
int f(int a, int b){
	int result = 1;
for (int i = 1; i < 20; i++){
		result = result * a;
		if (result == b)
		{
			return i;
		}
	}
      return -1;
}
int main(){
	int a = 0;
	int b = 0;
	scanf("%d", &a);
	scanf("%d", &b);
     if (f(a, b) >= 0)
		printf("%d ^ %d = %d\n",a,f(a, b),b);
	 else if (b == 1) 
		 printf("%d ^ 0 = %d \n",a,b);
	 else printf("%d ^ not degree = %d\n",a,b);
	}
