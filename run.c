#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

#include "run.h"
#include "util.h"

void *base = 0;
p_meta last = 0;

p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  switch(fit_flag){
    case FIRST_FIT:
    {
      while(index){
	if(index->free == 1 && index->size >= size){
	  result = index;
	  break; 
	}
	index = index->next;
      }
    }
    break;

    case BEST_FIT:
    {
      p_meta tmp = index;

      while(index){
	if(index->free == 1 && index->size >= size && index->size < tmp->size){
	  tmp = index;
	}
	  if(tmp == last)
		break;
	  index = index->next;	
      }
	result = tmp;      

    }
    break;

    case WORST_FIT:
    {
       p_meta tmp = index;

      while(index){
	if(index->free == 1 && index->size >= size && index->size > tmp->size){
	  tmp = index;
	}
	  if(tmp == last)
		break;
	  index = index->next;	
      }
	result = tmp;  
    }
    break;

  }
  return result;
}

void *m_malloc(size_t size) {

  if(!size)
    return NULL;

  if(size % 4)
    size = (size/4+1)*4;

  p_meta find = find_meta(&last, size);
  struct rlimit tmplimit;

  if(find == NULL){
	p_meta tmp = (p_meta)malloc(META_SIZE+size);	

	if(tmp==NULL){
	  getrlimit(RLIMIT_AS, &tmplimit);
	  if(sbrk(0) +size + META_SIZE > tmplimit.rlim_max){
		return NULL;
	  }
	if(brk(size + META_SIZE) == -1)
		return NULL;

	tmp = (p_meta)malloc(META_SIZE + size);
	}

	tmp->free = 0;
	tmp->size = size;

	if(!base){
	  last = tmp;
	  tmp -> prev = NULL;
	  tmp -> next = NULL;
	  base = tmp;
	}
	else{
		tmp->prev = last;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}

	return (char*) tmp->data;
  } else {
	if(find->size - size > META_SIZE){
		int findsize = find->size - size - META_SIZE;
		p_meta prev = find->prev;
		p_meta next = find->next;
		free(find);
		prev -> next = (p_meta)malloc(META_SIZE + size);
		find = prev->next;
		find-> next = (p_meta)malloc(META_SIZE + findsize);
		find->size =size;
		find -> next ->size = findsize;
		find->free = 0;
		find->next->free =1;
		find->prev = prev;
		find->next->next = next;
		next->prev = find->next;
		find->next->prev = find;
	}
	find ->free =0;
	return (char*) find ->data;
  }


}

void m_free(void *ptr) {

}

void*
m_realloc(void* ptr, size_t size) {

}
