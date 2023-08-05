#include <stddef.h>


/*returns the length of the pcStr
 * it checks for runtime error for pcStr == null */
size_t ms_lenght(const char *pcStr);


/*copies the StrToCopy in the StriWrite and ads
 * the \0 at the end to comply with the string format
 *  it checks for runtime error for strToWrite == null
 *  and  strToCopy == null*/
void ms_copy(char *strToWrite, const char *strToCopy);


/*copies num characters of StrToCopy in the StriWrite and
 * ads the \0 at the end to comply with the string format
 *  it checks for runtime error for strToWrite == null
 *  and  strToCopy == null*/
void ms_ncopy(char *strToWrite, const char *strToCopy, size_t num);


/*copies the secondStr at the end of the startingStr
 *  it checks for runtime error for startingStr == null
 *  and  secondStr == null*/
void ms_concat(char *startingStr, const char *secondStr);


/*copies num chars of the secondStr at the end of the startingStr
 *  it checks for runtime error for startingStr == null
 *  and  secondStr == null*/
void ms_nconcat(char *startingStr, const char *secondStr, size_t num);

/*compares the firstStr with the secondStr 
 * if they are the same it returns 0 else >0
 * if in the fist non equal pear the fist had the 
 * biggest char and <0 if the the biger char was from the
 * second str
 * it checks for runtime error for firstStr == NUll 
 * and secondStr == NULL*/
int ms_compare(const char *firstStr, const char *secondStr);


/*compares num cahrs of the firstStr with the secondStr 
 * if they are the same it returns 0 else >0
 * if in the fist non equal pear the fist had the 
 * biggest char and <0 if the the biger char was from the
 * second str
 * it checks for runtime error for firstStr == NUll 
 * and secondStr == NULL*/
int ms_ncompare(const char *firstStr, const char *secondStr, size_t num);


/*atemps to find the toFind in the bigStr 
 * if successful it return a pointer of where that
 * substring starts in the bigStr
 * it checks for runtime error for bigStr == NULL
 * and toFind == NUll*/
char* ms_search(char *bigStr, char *toFind);

