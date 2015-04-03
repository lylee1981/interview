//给定一个整数集合，例如{2，3，0，5，6}，找出连续的子集使得乘积最大

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct exclued_closed_s exclued_closed_t;

struct exclued_closed_s {

    int index[128];
    int max;
    int len;
};


void printSubset(int a[], size_t len);

void 
printSubset(int a[], exclued_closed_t *p) {

    size_t len = p->len;

    int i;
    if (len <= 0) {
        return;
    }
    cout << "subset: ";
    for (i = 0; i < len; i++) {
        cout << a[p->index[i]] << " ";
    }
    cout << endl;
}

int getIntArrayLength(size_t size);
int 
getIntArrayLength(size_t size) {
    
    int intSize = sizeof(int);
    
    return size / intSize;
}

static exclued_closed_t *findSubSq(int array[], size_t len);

static exclued_closed_t *
findSubSq(int array[], size_t len) {

    exclued_closed_t        *p, *temp;
    int                      result;
    int                      i, j, last;
    int                      create_new_item;
    int                      tmp, max;
    int                      idx;
    int                      last_oped;  // is last item has been add or freed
    queue<exclued_closed_t*> queue;
    size_t                   active_queue_len;

    if (len == 0 || len == 1) {
        return NULL;
    }

    int a[len];
    for (i = 0; i < len; i++) {
        a[i] = array[i];
    }
    
    //len >= 2
    create_new_item = 0;
    i = 0;
    j = 1;
    idx = 0;
    last_oped = 0;
    last = a[idx];  //设置第一个元素值
    
    //找到一个非0，非负数的索引号，有可能是第一个数
    while(last <= 0) {
        idx++;
        tmp = a[idx];
        if (tmp > 0) {
            break;
        }
        last *= tmp;
        if(idx == len - 1) {
            break;
        }
    }

    if(idx == len -1) {
        return NULL;
    }
    
    // create first item
    p = (exclued_closed_t *)malloc(sizeof(exclued_closed_t));
    
    //设置第一个正整数的索引号，并修改长度
    p->len = 0;
    p->index[p->len] = idx;
    p->len++;

    //从第一个正数开始，到任何一个非正数结束，过程中记录所有的index和乘机数
    //遇到非正数，调整新的startIdx为非正数的下一个，直到结束

    //获取第一个正数
    max = a[idx];
    for(i=idx+1; i < len; i++) {
        tmp = a[i];
        
        if(tmp <=0) {    //set create_new_item is true
            if(last_oped == 0) {
                if(p->len <= 1) {
                    free(p);    // if item 's value less 1 or 0, free item node and not add 2 queue
                    last_oped = 1;

                } else {
                    queue.push(p);   //add item to queue
                    last_oped = 1;
                }
            }

            create_new_item = 1;
            continue;
        }

        if(create_new_item) {
            p = (exclued_closed_t *)malloc(sizeof(exclued_closed_t));
            p->len = 0;
            max = 1;
            create_new_item = 0;
            last_oped = 0;
        }

        max *= tmp;
        
        //数字大于0
        p->index[p->len] = i;
        p->len++;
        p->max = max;        

        if (i == len -1) {
            if(last_oped == 0) {
                queue.push(p);   //add item to queue
                last_oped = 1;
            }
        }
    }

    max = 0;
    p = NULL;
    temp = NULL;
    

    // using queue Instead vector for release resource

    active_queue_len = queue.size();
    cout << "queue 's count: " << active_queue_len << endl;

    if(active_queue_len <= 1) {
    
        p = queue.front();
        queue.pop();

        return p;
    }

    while (!queue.empty()) {
        temp = queue.front();
        queue.pop();

        printSubset(a, temp);

        last = temp->max;

        // this condition always true, because queue 's item 's max all bigger than zero
        if(last > max) {
            max = last;
            if(p == NULL) {
                p = temp;
            } else {
            
                free(p);
                p = temp;
            }
        } else {
        
            free(temp);
        }
    }

    return p;    
}

int main(void) {

    exclued_closed_t *p;
    int               i;

    int a[] = {2, 2, 3, 4, -1, 0, 5, 7 };
    //int a[] = {2, 2, 3, 4, -1, 0, 5, 7, 100 };
    //int a[] = {-1, 0, 3, 4, -1, 0, 5, 1 };
    //int a[] = {-1};
    //int a[] = {0, -1};
    //int a[] = {0, -1, 1, 0, 3, -5, 9, 0};
    size_t len = getIntArrayLength(sizeof(a));
    
    cout << "sizeof array len: " << sizeof(a) << endl;
    cout << "len: " << len << endl;
    
    p = findSubSq(a, len);
    
    if(p == NULL) {
        cout << "no match item" << endl;
        return -1;
    }
    
    cout << "max value: " << p->max << endl;
    for(i = 0; i < p->len; i++) {
        cout << "item: " << a[p->index[i]] << endl;
    }
    
    free(p);
    
    return 0;   
}
