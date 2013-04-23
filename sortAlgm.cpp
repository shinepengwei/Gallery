#include<stdio.h>
#include<iostream>
using namespace std;
void printlist(int *list,int n){
    for(int i=0;i<n;i++)
        std::cout<<list[i]<<",";
    cout<<endl;
}
void swap(int *list,int i,int j){
    int tmp=list[i];
    list[i]=list[j];
    list[j]=tmp;
}
//直接插入排序，其中list[0]作为哨兵，并不参与排序，排序后的序列为list[1~n-1]
// int n=10,list[11]={-1,4,1,3,2,16,9,10,14,8,7}, InsertSort(list,11);
void InsertSort(int *list,int n){
    for(int i=2;i<n;i++){
        list[0]=list[i];
        int j=i-1;
        while(list[j]>list[0]){
            list[j+1]=list[j];
            j--;
        }
        list[j+1]=list[0];
    }
}

//折半插入int n=10,list[11]={-1,4,1,3,2,16,9,10,14,8,7}，BInsertSort(list,11);
void BInsertSort(int *list,int n){
    int low,high,mid;
    for(int i=2;i<n;i++){
        list[0]=list[i];
        high=i-1;
        low=1;
        while(high>=low){
            mid=(high+low)/2;
            if(list[mid]>list[0]) high=mid-1;
            else low=mid+1;
        }
        for(int j=i-1;j>high;j--) list[j+1]=list[j];
        list[high+1]=list[0];
    }
}

//shell排序
//int int list[11]={-1,4,1,3,2,16,9,10,14,8,7};    ShellSort(list,10);
void ShellPass(int *list, int n, int d){
    for(int i=1+d;i<=n;i++){
        if(list[i]<list[i-d]){
            list[0]=list[i];
            int j=i-d;
            do{
                list[j+d]=list[j];
                j=j-d;
            }while(j>0&&list[j]>list[0]);
            list[j+d]=list[0];
        }
    }
}
void ShellSort(int *list,int n){
    cout<<"before:"<<endl;
    printlist(list,11);
    int increment=n;//增量初值
    do{
        increment=increment/3+1;
        ShellPass(list,n,increment);
        cout<<increment<<":"<<endl;
        printlist(list,11);
    }while(increment>1);
}

//冒泡排序int list[10]={4,1,3,2,16,9,10,14,8,7};    BubbleSort(list,10);
void BubbleSort(int *list,int n){
    for(int i=1;i<n;i++){
        bool exchange=false;
        for(int j=0;j<n-i;j++){
            if(list[j]>list[j+1]){
                int tmp=list[j];
                list[j]=list[j+1];
                list[j+1]=tmp;
                exchange=true;
            }
        }
        if(!exchange){
            return;
        }
    }
}

//快速排序
int Partition(int *list,int low,int high){
    int pivot=list[low];
    while(low<high){
        while(list[high]>pivot&&low<high) high--;
        if(high>low){
            //交换high和low的元素
            //swap(list,high,low);
            //将pivot存储在变量中，应该存放PIVOT的元素一直为NULL
            list[low]=list[high];
            low++;
        }
        while(list[low]<pivot&&low<high) low++;
        if(high>low){
           // swap(list,high,low);
            list[high]=list[low];
            high--;
        }
    }
    //最后high=low
    list[low]=pivot;//最后将这个一直为NULL的元素放入pivot
        return low;
    
}
//int list[11]={4,1,3,2,16,9,10,14,8,7};QuickSort(list,0,9);
void QuickSort(int *list,int low,int high){
    int pivotpos;
    if(low<high){
        pivotpos=Partition(list,low,high);
        //printlist(list,10);
        QuickSort(list,low,pivotpos-1);
        QuickSort(list,pivotpos+1,high);
    }
        
}
// int list[10]={4,1,3,2,16,9,10,14,8,7};   SelectSort(list,10);
void SelectSort(int *list,int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(list[j]<list[min]){
                min=j;
            }
        }
        if(i!=min)
            swap(list,i,min);
    }
}
//并归排序
void Merge(int *list,int *tmp,int begin,int mid,int end){
    int i=begin,j=mid+1,k=begin;
    while(i<=mid&&j<=end){
        if(list[i]>list[j]){
            tmp[k]=list[j];
            j++;
        }else{
            tmp[k]=list[i];
            i++;
        }
        k++;
    }
    while(i<=mid){
        tmp[k]=list[i];
        k++;
        i++;
    }
    while(j<=end){
        tmp[k]=list[j];
        k++;
        j++;
    }
    for(i=begin;i<=end;i++){
        list[i]=tmp[i];
    }
}
void MSort(int *list,int begin,int end,int *tmp){
    if(begin<end){
        int mid=(begin+end)/2;
        MSort(list,begin,mid,tmp);
        MSort(list,mid+1,end,tmp);
        Merge(list,tmp,begin,mid,end);
    }
}
//int list[11]={-1,4,1,3,2,16,9,10,14,8,7};MergeSort(list,10);
void MergeSort(int *list,int n){
    int *p=new int[n+1];
    for(int i=0;i<n+1;i++)
        p[i]=-1;
    MSort(list,1,n,p);
    delete []p;
}
//Heap Sort
//从数组索引为1的地方开始排序，为了计算方便
int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}
int parent(int i){
    return i/2;
}
void maxHeapify(int *list,int i,int size){
    int l=left(i);
    int r=right(i);
    int largest=i;
    if(l<size&&list[l]>list[i]){
        largest=l;
    }
    if(r<size&&list[r]>list[largest]){
        largest=r;
    }
    if(i!=largest){
        swap(list,i,largest);
        maxHeapify(list,largest,size);
    }
}
void BuidHeap(int *list,int size){
    for(int i=size/2;i>=1;i--){
        maxHeapify(list,i,size);
    }
}
//size=list.length()-1, don't consider the first element of list,list[0]
//int list[11]={-1,4,1,3,2,16,9,10,14,8,7};HeapSort(list,10);
void HeapSort(int *list,int size){
    BuidHeap(list,size);
    while(size>0){
        swap(list,1,size);
        maxHeapify(list,1,size);
        size--;
    }

}

void main(){
    int list[11]={-1,4,1,3,2,16,9,10,14,8,7};
    printlist(list,11);
    HeapSort(list,10);
    printlist(list,11);
    int x;
    cin>>x;
}
