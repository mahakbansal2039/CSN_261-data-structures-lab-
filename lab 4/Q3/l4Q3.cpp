#include<iostream>
#include<unordered_map>
#include <bits/stdc++.h> 
using namespace std;
int start;
int lenOfLOngSubarr(int *array,int n,int k);
int main()
{

	int n;
	int k;
	cout<<"enter the number of elements of array "<<endl;
	cin>>n;
	int *array;
	array=new int[n];
	for(int i=0;i<n;i++)
		cin>>array[i];
	cout<<"enter the value of n ";
	cin>>k;
	int length=lenOfLOngSubarr(array,n,k);
	cout<<"length of longest subarray is "<<length<<endl;
	cout<<"start index :"<<start<<"  "<<"end index :"<<start+length-1<<endl;

}
int lenOfLOngSubarr(int *array,int n,int k)
{

	unordered_map<int ,int >um;
	int sum=0;
	 start=0;
	int maxlen=0;
	for(int i=0;i<n;i++)
	{
		sum+=array[i];
		if(sum==k)
			maxlen=i+1;
		if(um.find(sum)==um.end())
			um[sum]=i;
		if(um.find(sum-k)!=um.end())
		{
			if(maxlen<(i-um[sum-k]))
				{
					maxlen=i-um[sum-k];
					start=um[sum-k]+1;
				}



		}

	}
return maxlen;

}