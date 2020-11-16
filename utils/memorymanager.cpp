/*
 * memorymanager.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

//TODO organize includes
#include "../includes/constants.h"
#include "../includes/memorymanager.h"
/**
 * this will hold the list of structs
 */
data *list_data=0;

/**
 * create a linked list of  structs.
 * NOTE: be sure you do not leak memory if you call this function twice!
 *       IOW deallocate any exixting list before reallocating
 *
 * \param total_memory: the maximum memory to use
 * \return if a positive number, then its the number of structs created
 *         if 0, then there is not enough memory to allocate a struct
 * 		   MEM_ALREADY_ALLOCATED  if memory has already been allocated, this
 * 		   						  is indicated by total_allocated>0. (BTW why use
 * 		   						  total_allocated instead of list_data==0?)
 */
int create_list(int total_memory){

}

/**
 * deallocate the list of structs, easiest way is to start at the beginning
 * and delete as you go, dont forget to set list_data to null when done
 *
 * \return SUCCESS if memory deallocated
 *         NO_STRUCTS_TO_DEALLOCATE if no memory allocated
 */
int destroy_list(){

}

/**
 * How many structs are available in list_data
 *
 * \return number structs available
  */
int numb_available_structs(){

}

/**
 *returns the list for client use
 *
 * \return 	pointer to list
 * 			0 if the list his empty
 *
 */
data*  get_list(){

}
