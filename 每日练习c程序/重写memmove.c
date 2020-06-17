//÷ÿ–¥memmove
#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma comment(lib,"Winmm.lib")
#pragma warning(disable:4996)
void *memmove2(void* dest, const void* src, size_t count){
	if (dest == NULL || src == NULL) return NULL;
	void *p = malloc(count);
	for (int i = 0; i < count; i++){
		*((char*)p + i) = *((char*)src + i);
	}
	for (int i = 0; i < count; i++){
		*((char*)dest + i) = *((char*)p + i);
	}
	free(p);
	return dest;
}
int main(){
	char s[] = "1234567890";
	char* p1 = s;
	char* p2 = s + 2;
	memmove2(p2, p1, 5);
	printf("%s\n", s);
	system("pause");
	return 0;
}