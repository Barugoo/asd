#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

const int max_size = 3;

void vector_init(vector *v)
{
	v->items = malloc(sizeof(item*) * max_size);
	v->len = 0;
	v->cap = max_size;
}

item *vector_get(vector *v, int key)
{
    int i;
    for (i = 0; i < v->len; i++)
    {
        if (v->items[i]->key == key) return v->items[i];
    }
	return NULL;
}

int vector_len(vector *v)
{
	return v->len;
}

void vector_add(vector *v, item *e)
{
	if (v->len == max_size)
	{
		printf("ERROR: vector is full");
		return;
	}
	
	if (v->len == 0)
	{
		v->items[0] = e;
		v->len++;
		return;
	}

    if (vector_get(v, e->key) != NULL)
    {
        printf("ERROR: dublicate key entry %d\n", e->key);
        return;
    }


	int i, found = 0;
	item* tmp1 = e; 
	item* tmp2;
	for (i = 0; i<=v->len; i++)
	{
		if (i == v->len)
		{
			v->items[i] = tmp1;
			break;
		}
		if (e->key < v->items[i]->key) 
		{
			tmp1 = v->items[i];
			if (found == 0)
			{
				v->items[i] = e;
				found = 1;
			} else {
				v->items[i] = tmp2;
				tmp2 = tmp1;
			}
		}
	}
	v->len++;

}

void vector_set(vector *v, int key, item *e)
{ 
	item* elem;
	elem = vector_get(v, key);
	if (elem == NULL) {
        printf("ERROR: key doesn't exist %d\n", e->key);
		return;
	}
	free(elem->value);
	elem->value = e->value;
}

void vector_delete(vector *v, int key)
{
	int i, j, found = 0;

	item **newarr = (item**)malloc(sizeof(item*) * v->len);
	for (i = 0, j = 0; i < v->len; i++, j++) {
		if (v->items[i]->key == key)
		{
			found = 1;
			j++;
		}
		newarr[i] = v->items[j];
	}
	if (found == 0){
		free(newarr);
		printf("ERROR: key doesn't exist %d\n", key);
		return;
	}

	free(v->items);

	v->items = newarr;
	v->len--;
}

void vector_free(vector *v)
{
	free(v->items);
}

int main(void)
{
	vector v;
	vector_init(&v);

	int input = -1;
	while (input != 0){
		printf("\nmenu:\n1.add\n2.delete\n3.get by key\n4.ranged get\n5.list\n0.exit\n");
		scanf("%d",&input);
		switch(input){
			case 1:
			{
				char* value = (char*)malloc(sizeof(char)*100);
				int key;
				printf("input key (int) and value (string): ");
				scanf("%d",&key);
				scanf("%[^\n]s",value);

				item* elem = (item*)malloc(sizeof(item));
				elem->key = key;
				elem->value = value;
				vector_add(&v, elem);

				break;
			}
			case 2:
			{
				int key;
				printf("input key (int): ");
				scanf("%d",&key);

				vector_delete(&v, key);
				break;
			}
			case 3:
			{
				int key;
				printf("input key (int): ");
				scanf("%d",&key);
			
				item* elem;
				elem = vector_get(&v, key);
				if (elem == NULL) {
					printf("ERROR: key doesn't exist %d\n", key);
					break;
				}
				printf("value is: %s\n", elem->value);
				break;
			}
			case 4:
			{
				vector vNew;
				vector_init(&vNew);

				item* elem;

				int i, key1, key2;
				printf("input key1 (int) and key2 (int): ");
				scanf("%d",&key1);
				scanf("%d",&key2);

				for (; key1 <= key2; key1++) {
					elem = vector_get(&v, key1);
					if (elem != NULL)
					{
						vector_add(&vNew, elem);
					}
				}

				printf("result vector:\n");
			
				for (i = 0; i < vNew.len; i++){

					printf("%d.", i+1);
					printf("key: %d; ", vNew.items[i]->key);
					printf("value: %s\n", vNew.items[i]->value);

				}
				v = vNew;
				break;
			}
			case 5:
			{
				int i;
				for (i = 0; i < v.len; i++){

					printf("%d.", i+1);
					printf("key: %d; ", v.items[i]->key);
					printf("value: %s\n", v.items[i]->value);

				}
				break;
			}		
		}
	}

}