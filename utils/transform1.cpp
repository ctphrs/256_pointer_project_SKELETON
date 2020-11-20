/*
 * transform1.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */
#include<string>
/**
 * transforms a lowercase char to an uppercase one
 * for instance 'a' to 'A'. Has no effect on non-
 * alphabetic characters.  islower may be of use
 *
 * \param pchar char to transform
 * \return bool - 	true - transform occurred
 * 					false - either pchar is null or its not an alhabetic char
 */
bool transform(char *pchar){
	if(isalpha(*pchar)){
		*pchar = toupper(*pchar);
	}
	else{
		return false;
	}
	return true;
}
