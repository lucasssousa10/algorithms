#include <stdio.h>
int main() {
	int n, i, j, maior; 
	int freq[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char str[201], *p;
	
	scanf("%d", &n); 
	getchar();
	
	for(i = 0; i < n; i++) {
		gets(str);
		p = str;
		maior = 0;
		while(*p != '\0') {
			if(*p >= 'A' && *p <= 'Z') {
				freq[(*p) - 'A']++;
				maior = (freq[(*p) - 'A'] > maior ? freq[(*p) - 'A'] : maior);
			}
			if(*p >= 'a' && *p <= 'z') {
				freq[(*p) - 'a']++;
				maior = (freq[(*p) - 'a'] > maior ? freq[(*p) - 'a'] : maior);
			}
			p++;
		}

		for(j = 0; j < 26; j++) {
			if(freq[j] == maior) {
				printf("%c", j + 'a');
			}
			freq[j] = 0;
		}
		printf("\n");
	}

	return 0;
}