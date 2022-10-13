// Count of an Element in a Sorted Array (Sorted Array dekha aur Binary Search laga Dala)
// Using Binary Search as it makes time Complexity O(logn)

#include<iostream>
using namespace std;


int BinarySearch(int arr[],int n,int k,bool SearchFirst){
	int start = 0;
	int end = n - 1;
	int res = -1;
	
	while(start <= end){
		int mid = start + (end - start)/2;     // To Avoid Overflow 
		
		if(k == arr[mid]){
			res = mid;
			
			if(SearchFirst == true){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
		else if(k > arr[mid]){
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return res;
}
int main()
{
	int A[20],size,key;
	cout <<"\n\nEnter the size of array : ";
	cin>>size;
	
	cout<<"\n\nEnter the element of array : ";
	for(int i = 0;i < size;i++){
		cin>>A[i];
	}
	cout<<"\n\nArray  = ";
	for(int i = 0;i < size;i++){
		cout<<A[i]<<" ";
	}
	
	cout<<"\n\nEnter the key to Search : ";
	cin>>key;
	
	int first = BinarySearch(A,size,key,true);
	
	int last = BinarySearch(A,size,key,false);
	
	cout <<"\n\nFirst Occurence of " << key << " is at index " << first <<endl;
	cout <<"\n\nLast Occurence of " << key << " is at index " << last <<endl;
	
	int count = last - first + 1;
	
	if(first != -1){
		cout <<"\n\nElement "<< key << " occurs " << count <<" times ";
	}
	else 
	cout <<"\n\nElement not found ! ";
	cout<<endl<<endl;


	return 0;
}
