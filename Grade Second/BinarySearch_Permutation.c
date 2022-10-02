#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

int BinarySearch(int arr[],int target,int low,int high){
    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] == target){
            return mid;
        }else if(target > arr[mid]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return 0;
}

int BinarySearch_recusive(int arr[],int target,int low,int high){
    int mid = (low + high)/2;

    if(arr[mid] == target){
        return mid;
    }else if(target > arr[mid]){
        return BinarySearch(arr,target,mid+1,high);
    }else{
        return BinarySearch(arr,target,low,mid-1);
    }

    return 0;
}



void perm(char *list,int k,int j)
{
	char temp;
	int i;
	if(k==j)
	{
		printf("%s\n",list);
	}
	else
	{
		for(i=k;i<=j;i++)
		{
            printf("!%d %s!\n",k,list);
			SWAP(list[i],list[k],temp);
			perm(list,k+1,j);
			SWAP(list[i],list[k],temp);
		}
	}
}



int main(){
    
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int target = 5;
    int location = BinarySearch(arr,target,0,sizeof(arr)/sizeof(arr[0])-1);

    if(location) printf("%d in arr[%d]\n",target,location);
    else printf("NO FOUND\n");

    char list[] = "abc";
    perm(list, 0, 2);
    system("pause");

}
