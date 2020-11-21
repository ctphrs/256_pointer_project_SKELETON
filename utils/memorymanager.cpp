/*
 * memorymanager.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

#include "../includes/constants.h"
#include "../includes/memorymanager.h"
#include "../includes/utilities.h"
/**
 * this will hold the list of structs
 */
data *list_data = 0;
int total_allocated = 0;
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
	if(total_allocated>0){
		return MEM_ALREADY_ALLOCATED;
	}
	int max_num_structs = how_many_structs_can_fit_in_memory(total_memory);
	if(max_num_structs == 0){
		return 0;
	}
	list_data = new data;
	data *pinter = list_data;
	total_allocated++;
	for(int i=1;i<max_num_structs;i++){
		struct data *new_data = (struct data*) malloc(sizeof(struct data));
		pinter -> p_next = new_data;
		pinter = new_data;
		total_allocated++;
	}

	return total_allocated;

}

/**
 * deallocate the list of structs, easiest way is to start at the beginning
 * and delete as you go, dont forget to set list_data to null when done
 *
 * \return SUCCESS if memory deallocated
 *         NO_STRUCTS_TO_DEALLOCATE if no memory allocated
 */
int destroy_list(){
	if(!list_data){
		return NO_STRUCTS_TO_DEALLOCATE;
	}
	data *temp = new data;
	temp = list_data;
	while(temp){
		list_data=list_data->p_next;
		delete(temp);
		temp = list_data;
	}
	total_allocated = 0;
	return SUCCESS;
}

/**
 * How many structs are available in list_data
 *
 * \return number structs available
  */
int numb_available_structs(){
	int count = 0;
	struct data *pinter = list_data;
	while(pinter != NULL){
		count++;
		pinter = pinter -> p_next;
	}
	return count;
}

/**
 *returns the list for client use
 *
 * \return 	pointer to list
 * 			0 if the list his empty
 *
 */
data*  get_list(){
return list_data;
}
