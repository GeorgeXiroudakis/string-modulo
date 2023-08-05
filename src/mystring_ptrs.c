#include "mystring.h"
#include <assert.h>
#include <stddef.h>


/*returns the length of the pcStr
 * it checks for runtime error for pcStr == null */
size_t ms_lenght(const char *pcStr){
	const char *pcStrEnd = pcStr;
	assert(pcStr != NULL);
	while( *pcStrEnd != '\0')
		pcStrEnd++;
	return pcStrEnd - pcStr;
}


/*copies the StrToCopy in the StriWrite and ads
 * the \0 at the end to comply with the string format
 *  it checks for runtime error for strToWrite == null
 *  and  strToCopy == null*/
void ms_copy(char *strToWrite, const char *strToCopy){
	assert(strToCopy != NULL);
	assert(strToWrite != NULL);

	while(*strToCopy != '\0'){
		*strToWrite = *strToCopy;
		strToCopy++;
		strToWrite++;
	}
	*strToWrite = '\0';
	return ;
}


/*copies num characters of StrToCopy in the StriWrite and
 * ads the \0 at the end to comply with the string format *  it checks for runtime error for strToWrite == null
 *  and  strToCopy == null*/
void ms_ncopy(char *strToWrite, const char *strToCopy, size_t num){
	assert(strToCopy != NULL);
	assert(strToWrite != NULL);

	while(num > 0){	
		*strToWrite = *strToCopy;
		strToCopy++;
		strToWrite++;
		num--;
	}
	*strToWrite = '\0';

	return ;
}


/*copies the secondStr at the end of the startingStr
 *  it checks for runtime error for startingStr == null
 *  and  secondStr == null*/
void ms_concat(char startingStr[], const char secondStr[]){
	startingStr += ms_lenght(startingStr);
	
	while (*secondStr != '\0'){
		*startingStr = *secondStr;
		startingStr++;
		secondStr++;
	}
	*startingStr = '\0';

	return ;
}


/*copies num chars of the secondStr at the end of the startingStr
 *  it checks for runtime error for startingStr == null
 *  and  secondStr == null*/
void ms_nconcat(char *startingStr, const char *secondStr, size_t num){	
	size_t i;
	startingStr += ms_lenght(startingStr);
	
	for(i = 0; i < num; i++){
		*startingStr = *secondStr;
		startingStr++;
		secondStr++;
	}
	*startingStr = '\0';

	return ;	
}


/*compares the firstStr with the secondStr
 * if they are the same it returns 0 else >0
 * if in the fist non equal pear the fist had the 
 * biggest char and <0 if the the biger char was from the
 * second str
 * it checks for runtime error for firstStr == NUll 
 * and secondStr == NULL*/
int ms_compare(const char *firstStr, const char *secondStr){
	assert(firstStr != NULL);
	assert(secondStr != NULL);

	while(*firstStr != '\0' || *secondStr != '\0'){
		if(*firstStr != *secondStr)return *firstStr - *secondStr;
		firstStr++;
		secondStr++;
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
int ms_ncompare(const char *firstStr, const char *secondStr, size_t num){	
	size_t i;
	assert(firstStr != NULL);
	assert(secondStr != NULL);

	i = 0;
	while( (*firstStr != '\0' || *secondStr != '\0') && i < num){
		if(*firstStr != *secondStr)return *firstStr - *secondStr;
		firstStr++;
		secondStr++;
		i++;
	}
	return 0;
}


/*atemps to find the toFind in the bigStr 
 * if successful it return a pointer of where that
 * substring starts in the bigStr
 * it checks for runtime error for bigStr == NULL
 * and toFind == NUll*/
char* ms_search(char *bigStr, char *toFind){
	char *last_of_find;
	char *start;
	char *ogFind;

	assert(bigStr != NULL);
	assert(toFind != NULL);
	
	start = NULL;
	last_of_find = toFind + ms_lenght(toFind);
	ogFind = toFind;
	while(*bigStr != '\0'){
		/*if we get threw the hole toFind str 
		 * without restarting then we found 
		 * the hole string and return the start*/
		if(*toFind == *last_of_find)return start;

		/*if they match searching for the next to
		 * match*/
		if(*bigStr == *toFind){
			if(toFind == ogFind)
				start = bigStr; 	
			toFind++;
		/*if the don't match and we had found a match
		 * restart the search */
		}else if(start != NULL){
			toFind = ogFind;
			start = NULL;
			continue;
		}	
		bigStr++;
	}
	return NULL;
}



