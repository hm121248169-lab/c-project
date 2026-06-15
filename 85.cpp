#include<bits/stdc++.h>
using namespace std;
template<typename T>
	T largest_element(T arr[],int n){
		T max_val=arr[0];
		int i;
		for(i=1;i<n;++i){
			if(arr[i]>max_val){
				max_val=arr[i];
			}
		}
		return max_val;
	}
	
	int main(){
		int n1;
		cin>>n1;
		int arr_int[10];
		int i;
		for(i=0;i<n1;++i){
			cin>>arr_int[i];
		}
		cout<<largest_element(arr_int,n1)<<endl;
	
		int n2;
		cin>>n2;
		double arr_double[10];
		for(i=0;i<n2;++i){
			cin>>arr_double[i];
		}
		cout<<largest_element(arr_double,n2)<<endl;
		
		int n3;
		cin>>n3;
		char arr_char[10];
		for(i=0;i<n3;++i){
			cin>>arr_char[i];
		}
		cout<<largest_element(arr_char,n3)<<endl;
		
		return 0;
}
