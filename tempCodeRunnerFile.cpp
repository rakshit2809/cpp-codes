}

void merge_sort(int a[] , int s , int e){
    if(s>=e){
        return;
    }
    else{
            int mid= (s+e)/2;
            int x[100],y[100];
            for(int i=0;i<mid;i++){
                x[i]=a[i];
            }
            for(int i=mid;i<e;i++){
                y[i]=a[i];
            }
            merge_sort(x,0,mid);
            merge_sort(y,mid+1,e);
            merge_array(x,y,a,s,e);
    }