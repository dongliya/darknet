#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * @brief  创建一个链表
 * @param  
 * @return 链表指针
 */ 
list *make_list()
{
	list *l = malloc(sizeof(list));
	//链表长度
	l->size = 0;
	//链表头
	l->front = 0;
	//链表尾
	l->back = 0;
	return l;
}

/*
void transfer_node(list *s, list *d, node *n)
{
    node *prev, *next;
    prev = n->prev;
    next = n->next;
    if(prev) prev->next = next;
    if(next) next->prev = prev;
    --s->size;
    if(s->front == n) s->front = next;
    if(s->back == n) s->back = prev;
}
*/

/*
 * @brief  从链表尾部删除一个节点
 * @param  l    链表指针
 * @return void 
 */ 
void *list_pop(list *l){
    if(!l->back) return 0;
    node *b = l->back;
    void *val = b->val;
    l->back = b->prev;
    if(l->back) l->back->next = 0;
    free(b);
    --l->size;
    
    return val;
}

/*
 * @brief  从链表尾部插入一个节点
 * @param  l    链表指针
 *         val  节点数据
 * @return void 
 */ 
void list_insert(list *l, void *val)
{
	node *new = malloc(sizeof(node));
	new->val = val;
	new->next = 0;

	if(!l->back){
		l->front = new;
		new->prev = 0;
	}else{
		l->back->next = new;
		new->prev = l->back;
	}
	l->back = new;
	++l->size;
}

/*
 * @brief  从释放节点指针
 * @param  n    节点指针
 * @return void 
 */ 
void free_node(node *n)
{
	node *next;
	while(n) {
		next = n->next;
		free(n);
		n = next;
	}
}

/*
 * @brief  从释放链表指针
 * @param  l    链表指针
 * @return void 
 */ 
void free_list(list *l)
{
	free_node(l->front);
	free(l);
}

/*
 * @brief  从释放链表数据
 * @param  l    链表指针
 * @return void 
 */ 
void free_list_contents(list *l)
{
	node *n = l->front;
	while(n){
		free(n->val);
		n = n->next;
	}
}

/*
 * @brief  链表转换为数组
 * @param  l    链表指针
 * @return void 
 */ 
void **list_to_array(list *l)
{
    void **a = calloc(l->size, sizeof(void*));
    int count = 0;
    node *n = l->front;
    while(n){
        a[count++] = n->val;
        n = n->next;
    }
    return a;
}
