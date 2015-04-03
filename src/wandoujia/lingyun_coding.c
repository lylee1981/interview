


// 给定整数集合，例如{ 2, 3, 5, 3, 4}，规则是不能取相邻的数（首位算相邻），找出一个序列使得这个序列的和最大

typedef struct sqmax_s sqmax_t;

struct sqmax_s {

    size_t len;
    int arr[];
};


typedef struct exclued_closed_s_s exclued_closed_t;

struct exclued_closed_s {

    int index[];
    int max;
    int len;
};

int getIntArrayLength(int a[]);
int 
getIntArrayLength(int a[]) {
    
    int intSize = sizeof(int);
    size_t size = sizeof(a);  
    
    return size / intSize;
}

//查找给定数在数组中的索引
int findNumberIndex(int number, int a[]);

int 
findNumberIndex(int number, int a[]) {
    int i;    
    int len = getIntArrayLength(a);
        
    for(i=0; i < len; i++) {
        if(number = a[i]) {
            return i;            
        }
    }
    
    return -1;
}

//从给定的一个集合，以及给定的一个数中，剔除与这个数相邻的数，返回这个集合
exclued_closed_t *excluedClosedNumber(int curr, int a[]);

exclued_closed_t *
excluedClosedNumber(int curr, int a[]) {
    
    int currIndex = findNumberIndex(curr, a);
    int endIndex;
    int excluedIndex;
    exclued_closed_t *ret;
    int i;
    int max = 0;
    int idx= 0;
    
    int len = getIntArrayLength(a);
    
    if(currIndex == -1) {
        perror("item '%d' not exists, has logic error");
        exit(-1);
    }   
    
    
    //给定节点是头
    if(currIndex == 0) {
        endIndex = len - 2;
        excluedIndex = currIndex +1;
        
        ret = (exclued_closed_t *)malloc(sizeof(exclued_closed_t));
        //@@todo check ret NULL
        
        for (i=0; i <= endIndex; i++) {
            if(i != excluedIndex ) {
                ret->index[idx] = i;
                max += a[i];
                ret->len++;
                ret->max = max;                
            }
            
            idx++;
        }
    }
    //给定节点是尾
    else if (currIndex == len -1) {

        endIndex = 1;
        excluedIndex = currIndex -1;
        
        ret = (exclued_closed_t *)malloc(sizeof(exclued_closed_t));
        //@@todo check ret NULL
        
        for (i=currIndex; i > endIndex; i--) {
            if(i != excluedIndex ) {
                ret->index[idx] = i;
                max += a[i];
                ret->len++;
                ret->max = max;
            }
            
            idx++;
        }    
    }
    //给定节点在中间
    else {
    
        int ll = currentIndex +1;
        int x[ll];
        
        for(i=0; i < ll; i++) {
            x[i] = a[i];
        }
        
        ll = len - currentIndex
        int y[ll];
        
        for(i=currentIndex; i < ll; i++) {
            y[i] = a[i];
        }

               
        //构建两个数组完毕，但是当前数分别在数组中存在，最后要减去一次
        
        exclued_closed_t *p = excluedClosedNumber(curr, x);
        exclued_closed_t *q = excluedClosedNumber(curr, y);
        
        
        ret = (exclued_closed_t *)malloc(sizeof(exclued_closed_t));
        
        int idx = 0;
        ret->len = p->len + q->len -1;
        ret->max = p->max + q->max - curr;
        
        for(i=0; i < p->len; i++) {
            ret->index[idx] = p->index[i];
            idx++;
        }
        
        for(i=1; i< q->len; i++) {
            ret->index[idx] = q->index[i];
        }
        
        free(p);
        free(q);

    }    
    
    return ret;

}

static void calcSqMax(int a[]);

static 
void calcSqMax(int a[]) {
    
    int len = getIntArrayLength(a);
    if(len == 0) {
        return NULL;
    }
    
    vector<exclued_closed_t*> v;
    exclued_closed_t *p;
    
    int curr;
    int i;
    for(i = 0; i < len; i++) {
        curr = a[i];
        p = excluedClosedNumber(curr, a);
        if(p) {
            v.push(p);
        }
    }
    int last;    
    int max;
    last = max = 0;
    vector<exclued_closed_t*>::iterator iter; 
    for(iter = v.begin(); iter != v.end(); iter++) {
        last = iter->max;
        if(last > max) {
            max = last;
            p = iter;
        }
    }
    
    printf("max sq 's value: %d, and value list:\n", max);
    
    for(i=0; i < p->len; i++) {
        printf("%d ", a[p->index[i]]);
    }    
    
    //@@todo destory resource, 使用vector在遍历时销毁对应的项 可能会有问题。可以使用queue来替代vector来维护 exclued_closed_t 类型指针，再来销毁 
}


int main(void) {
    
    int arr[5] = {2, 3, 0, 5, 6};

    calcSqMax(arr);
    return 0;
}

/*
static 
sqmax_t *calcSqMax(int a[]) {

    int i, j;
    sqmax_t *sqmax;
    int max, curr;
    int startIndex, endIndex;
    startIndex = 0;
    int next;
    
    curr = 0;

    int len = strlen(a);
    endIndex = len - 1;
    
    if (len == 0) {
        return NULL;
    }
    
    sqmax = (sqmax_t *)malloc(sizeof(sqmax_t));
    
    for(i = 0; i < len; i++) {
        next = i+1;
        max += a[i];
        for(j = next+1; j< len; j++) {
            max += a[j];
        }
        startIndex = i;
        curr+= a[startIndex];
        if (startIndex != next) {
            curr += a[startIndex];
        }
        startIndex++;
    }

}
*/