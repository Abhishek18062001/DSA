/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
int arr[100000];
void heapify (int arr[], int n, int i)
{
  int lar = i;
  int l = 2 * i + 1;
  int r = 2 *  i+ 2;
  if (l < n && arr[l] > arr[lar])
    {
      lar = l;
    }
  if (r < n && arr[r] > arr[lar])
    {
      lar = r;

    }
  if (lar != i)
    {
      swap(arr[lar],arr[i]);
      heapify (arr, n, lar);
    }
    return;
}

void buildheap (int arr[], int n)
{
  
  int l = n / 2 - 1;
  for (int i = l; i >= 0; i--)
    {
      heapify (arr, n, i);
    }
  for (int i = n - 1; i > 0; i--)
    {
      swap(arr[0],arr[i]);
      heapify (arr, i, 0);
    }

}

int main ()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
  buildheap (arr, n);
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }

  return 0;
}


