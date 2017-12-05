#ifndef _M_UTIL_H_
#define _M_UTIL_H_

#define FIRST_FIT 0
#define BEST_FIT 1
#define WORST_FIT 2

typedef struct query_s{

  char type;
  char val[256];

} query;

extern query *query_list;
extern char **alloc_list;
extern int query_cnt;
extern int mem_cnt;

extern int fit_flag;
extern int print_flag;

void print_block_list();

#endif
