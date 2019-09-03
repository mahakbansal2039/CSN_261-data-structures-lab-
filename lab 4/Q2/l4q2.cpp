#include<iostream>
using namespace std;
bool isSafe(int **board,int n);
bool solve(int **board,int col,int n);
void printarray(int** board,int n);
int main()
{
	cout<<"Enter the value of N :";
		int n;
		cin>>n;
	int **board;
	board=new int*[n];
	for(int i=0;i<n;i++)
		board[i]=new int[n];
	
	if(solve(board,0,n)==false)
		cout<<"No solution exist"<<endl;




}
bool isSafe(int **board,int row,int col,int n)
{
	int i,j;
	for(i=0;i<col;i++)
		{
			if(board[row][i])
			return false;
		}
		for(i=row,j=col;i>=0 && j>=0;i--,j--)
		{

			if(board[i][j])
				return false;
		}
		for(i=row,j=col;j>=0 && i<n;j--,i++)
			if(board[i][j])
				return false;

return true;

}
bool solve(int** board,int col,int n )
{
if(col==n)
{
	printarray(board,n);
	return true;

}
bool flag=false;
for(int i=0;i<n;i++)
{
	if(isSafe(board,i,col,n))
	{

		board[i][col]=1;
		flag=solve(board,col+1,n) || flag;
		board[i][col]=0;
	}




}
return flag;
}
void printarray(int **board,int n)
{
	static int k=1;
	cout<<k++<<endl;
	for(int i=0;i<n;i++)
	{

		for(int j=0;j<n;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}