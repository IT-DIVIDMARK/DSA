#include<stdio.h>
void display(int arr[] ,int n){
	int i ;
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
}
void heapify(int A[],int top,int last){
	int j,temp,key;
	key=A[top];
	j=2*top+1;
	if((j<last)&&(A[j]<A[j+1]))
		j=j+1;
	if((j<=last)&&(key<A[j]))
	{
		temp=A[top];
		A[top]=A[j];
		A[j]=temp;
		heapify(A,j,last);
	}
}

void buildheap(int A[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		heapify(A,i,n-1);
}

void heapsort(int A[],int n)
{
	int i,temp,top=0,last;
	buildheap(A,n);
	printf("lnitial heap=");
	display(A,n);
	for(last=n-1;last>=1;last--)
	{
		temp=A[top];
		A[top]=A[last];
		A[last]=temp;
		printf("\n After lteration%d:",n-last);
		display(A,n);
		heapify(A,top,last-1);
	}
}


int main(){
int A[8]={26,5,77,1,61,11,59,15};
heapsort(A,8);
printf("\nThe sorted element are:");
display(A,8);
return 0;
}
