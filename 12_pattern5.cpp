/*Problem statement
Sam is planting trees on the upper half region (separated by the left diagonal) of the square shared field.

For every value of ‘N’, print the field if the trees are represented by ‘*’.

Example:
Input: ‘N’ = 3

Output: 
* * *
* *
**/
#include<iostream>
using namespace std;
void seeding(int n) {
	for(int i=n;i>0;i--){
		for(int j=0;j<i;j++){
			cout<<"* ";
		}
		cout<<endl;
	}
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;  // Taking input from user
    seeding(n);  // Calling function
    return 0;
}