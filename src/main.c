/*uncoment line two to disable asserts*/
/*#define NDEBUG*/

#include <stdio.h>
#include "mystring.h"
#include <string.h>

int main(void){
	char s1[] = "George Xirudakis";
	char s2[1000];
	char s3[1000];
	char s4[1000];
	char s5[1000];
	
	int num;
	printf("\nThe length of the string: \"%s\" is: %ld\n",s1, ms_lenght(s1)) ;
	printf("using string.h: %ld\n\n", strlen(s1)) ;

	ms_copy(s2, s1);
	printf("Coping the string above to a new string result: \"%s\"\n", s2);
	strcpy(s2, s1);
	printf("using string.h result: \"%s\"\n\n", s2);

	num = 6;
	ms_ncopy(s3, s1, num);
	printf("Coping %d chars of the first string to a new string result: \"%s\"\n",num, s3);
	strncpy(s3, s1, num);
	printf("using string.h result: \"%s\"\n\n", s3);
	
	ms_copy(s4, s1);
	ms_concat(s4, s3);
	printf("concating the fisrt string with the last one(form ncopy) result: \"%s\"\n", s4);
	strcpy(s4, s1);
	strcat(s4, s3);
	printf("using string.h result: \"%s\"\n\n", s4);
		
	ms_copy(s5, s1);
	num = 2;
	ms_nconcat(s5, s3, num);
	printf("same as above put concasting %d chars result: \"%s\"\n", num, s5);	
	strcpy(s5, s1);
	strncat(s5, s3, num);
	printf("using string.h result: \"%s\"\n\n", s5);	

	printf("comparing the first with the second string(the one we copied) result: %s\n",
			ms_compare(s1, s2) ?
		       	"they are not same" : 
			"they are the same");
	printf("using string.h result: %s\n\n",
			strcmp(s1, s2) ?
		       	"they are not same" : 
			"they are the same");

	printf("comparing the first with the 4th string(the one we concated) result: %s\n",
			ms_compare(s1, s4) ?
		       	"they are not same" : 
			"they are the same");
	printf("using string.h result: %s\n\n",
			strcmp(s1, s4) ?
		       	"they are not the same" : 
			"they are the same");
		
	printf("comparing the first with the 4th string(the one we concated) with num = lengh(s1)");
	printf("(so we get the non concated) result: %s\n",
			ms_ncompare(s1, s4, ms_lenght(s1)) ?
		       	"they are not same" : 
			"they are the same");
	printf("using string.h result: %s\n\n",
			strncmp(s1, s4, strlen(s1)) ?
		       	"they are not the same" : 
			"they are the same");

	printf("comparing the first with the 4th string(the one we concated) with num = lengh(s1 + 1)");
	printf("(so we get the one char of the concated) result: %s\n",
			ms_ncompare(s1, s4, ms_lenght(s1) + 1) ?
		       	"they are not the same" : 
			"they are the same");
	printf("using string.h result: %s\n\n",
			strncmp(s1, s4, strlen(s1) + 1) ?
		       	"they are not the same" : 
			"they are the same");

	printf("using ms_search to find the \"is a\" in the \"this is a test\" result: %s\n"\
			, ms_search("this is a test", "is a"));
	printf("using string.h result: %s\n\n"\
			, strstr("this is a test", "is a"));

	
	return 0;
}
