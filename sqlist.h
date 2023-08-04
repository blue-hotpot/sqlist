typedef int data_t;//编译时处理
#define N 128//预处理展开

/*struct sqlist_t {
    data_t data[N];
    int last;
};
typedef struct sqlist_t sqlist;
typedef struct sqlist_t* sqlink;*/
typedef struct {
    data_t data[N];
    int last;//最后有意义的数据编号（0，1，2···）
}sqlist,*sqlink;

sqlink list_creat();
void list_clear(sqlink l);
void list_free(sqlink l);
int list_empty(sqlink l);
int list_length(sqlink l);
int list_locate(sqlink l,data_t value);
int list_insert(sqlink l,data_t value,int position);
int list_show(sqlink l);
int list_delete(sqlink l,int position);
int list_merge(sqlink l,sqlink q);
int list_purge(sqlink l);
int list_sort(sqlink l);
