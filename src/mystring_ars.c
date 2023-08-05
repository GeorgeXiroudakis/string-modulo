#include "mystring.h"
#include <assert.h>
#include <stddef.h>


/*returns the length of the pcStr
 * it checks for runtime error for pcStr == null */
size_t ms_lenght(const char pcStr[]){
	size_t uiLenght = 0u;
	assert(pcStr != NULL);
	while(pcStr[uiLenght] != '\0')
		uiLenght++;
	return uiLenght;
}


/*copies the StrToCopy in the StriWrite and ads
 * the \0 at the end to comply with the string format
 *  it checks for runtime error for strToWrite == null
 *  and  strToCopy == null*/
void ms_copy(char strToWrite[], const char strToCopy[]){
	size_t i;
	assert(strToCopy != NULL);
	assert(strToWrite != NULL);	
	i = 0;
	while(strToCopy[i] != '\0'){
		strToWrite[i] = strToCopy[i];
		i++;
	}
	strToWrite[i] = '\0';
	return ;
}


/*copies num characters of StrToCopy in the StriWrite and
 * ads the \0 at the end to comply with the string format
 *  it checks for runtime error for strToWrite == null
 *  and  strToCopy == null*/
void ms_ncopy(char strToWrite[], const char strToCopy[], size_t num){
	size_t i;
	assert(strToCopy != NULL);
	assert(strToWrite != NULL);	

	for(i = 0; i < num; i++){	
		strToWrite[i] = strToCopy[i];
	}
	strToWrite[i] = '\0';
	return ;
}

/*copies the secondStr at the end of the startingStr
 *  it checks for runtime error for startingStr == null
 *  and  secondStr == null*/
void ms_concat(char startingStr[], const char secondStr[]){
	size_t start_i;		
	size_t second_i;

	assert(startingStr != NULL);
	assert(secondStr != NULL);
	
	start_i = ms_lenght(startingStr);
	second_i = 0;
	while(secondStr[second_i] != '\0'){
		startingStr[start_i] = secondStr[second_i];
		start_i++;
		second_i++;
	}
	startingStr[start_i] = '\0';

	return ;
}


/*copies num chars of the secondStr at the end of the startingStr
 *  it checks for runtime error for startingStr == null
 *  and  secondStr == null*/
void ms_nconcat(char startingStr[], const char secondStr[], size_t num){
	size_t start_i;
	size_t second_i;

	assert(startingStr != NULL);
	assert(secondStr != NULL);
	
	start_i = ms_lenght(startingStr);
	for(second_i = 0; second_i < num; start_i++, second_i++)
		startingStr[start_i] = secondStr[second_i];
	
	startingStr[start_i] = '\0';
	return ;
}


/*compares the firstStr with the secondStr
 * if they are the same it returns 0 else >0
 * if in the fist non equal pear the fist had the 
 * biggest char and <0 if the the biger char was from the
 * second str 
 * it checks for runtime error for firstStr == NUll 
 * and secondStr == NULL*/
int ms_compare(const char firstStr[], const char secondStr[]){
	size_t i;
	assert(firstStr != NULL);
	assert(secondStr != NULL);

	i = 0;
	while(firstStr[i] != '\0' || secondStr[i] != '\0'){
		if(firstStr[i] != secondStr[i])return firstStr[i] - secondStr[i];

		i++;
	}
	return 0;
}


/*compares num cahrs of the firstStr with the secondStr
  if they are the same it returns 0 else >0
 * if in the fist non equal pear the fist had the 
 * biggest char and <0 if the the biger char was from the
 * second str
 * it checks for runtime error for firstStr == NUll 
 * and secondStr == NULL*/
int ms_ncompare(const char firstStr[], const char secondStr[], size_t num){
	size_t i;
	assert(firstStr != NULL);
	assert(secondStr != NULL);

	i = 0;
	while( (firstStr[i] != '\0' || secondStr[i] != '\0') && i < num){
		if(firstStr[i] != secondStr[i])return firstStr[i] - secondStr[i];

		i++;
	}

	return 0;
}


/*atemps to find the toFind in the bigStr 
 * if successful it return a pointer of where that
 * substring starts in the bigStr
 * it checks for runtime error for bigStr == NULL
 * and toFind == NUll*/
char* ms_search(char bigStr[], char toFind[]){
	size_t big_i;
	size_t find_i;
	size_t find_size;
	char *start;

	assert(bigStr != NULL);
	assert(toFind != NULL);
	
	big_i = 0;
	find_i = 0;
	start = NULL;
	find_size = ms_lenght(toFind);
	while(bigStr[big_i] != '\0'){
		/*if we get threw the hole toFind str 
		 * without restarting then we found 
		 * the hole string and return the start*/
		if(find_i == find_size)return start;
		
		/*if they match searching for the next to
		 * match*/
		if(bigStr[big_i] == toFind[find_i]){
			/*save start only on the first char*/
			if(find_i == 0)
				start = &(bigStr[big_i]);	
			find_i++;
		/*if the don't match and we had found a match
		 * restart the search */
		}else if(find_i != 0){
			find_i = 0;
			start = NULL;
			continue;
		}	
		big_i++;
	}
	return NULL;
}

