#include <sys/types.h>
#include <limits.h>

#include "run.h"
#include "util.h"

void *base = 0;

p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  switch(fit_flag){
    case FIRST_FIT:
    {
      while(sbrk(0) >= index){
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

      while(sbrk(0) >= index){
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

      while(sbrk(0) >= index){
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

}

void m_free(void *ptr) {

}

void*
m_realloc(void* ptr, size_t size)
{

}
