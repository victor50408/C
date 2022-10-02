#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a,int len){
    for(int i=0;i<len;i++){
        for(int k=0;k<len-1;k++){
            if(*(a+k)>*(a+k+1)){
                int t=*(a+k+1);
                *(a+k+1)=*(a+k);
                *(a+k)=t;
            }            
        }

    }
        
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len = nums1Size+nums2Size;
    int *combine = (int *)malloc(sizeof(int)*len);
    int counter = 0;
    for(int i=0;i<nums1Size;i++){
        combine[counter] = nums1[i];
        counter++;
    }
    for(int j=0;j<nums2Size;j++){
        combine[counter] = nums2[j];
        counter++;
    }

    bubble_sort(combine,len);

    if(len%2 == 0){
        double m = (double)combine[len/2] + (double)combine[len/2-1];
        return m/2;
    }else{
        return (double) combine[len/2];
    }
    
}


int main(){
    int a[]={1,3};
    int b[]={2,4};

    printf("%lf",findMedianSortedArrays(a,2,b,2));

    system("pause");
}

