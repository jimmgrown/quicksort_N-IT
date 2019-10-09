#include <iostream>
#include <ctime>
using namespace std;
int first, last;
int quicksort(int *mas, int first, int last)
{
   int mid, count;
   int f=first, l=last,k=0;
   mid=mas[(f+l) / 2];
   do
      {
         while (mas[f]%3==0){ k++;f++;}
         while (mas[l]%3!=0) l--;
         if (f<=l)
         {
            count=mas[f];
            mas[f]=mas[l];
            mas[l]=count;
            f++;
            l--;
            k++;
         }
      } while (f<l);
      return k-1;
}

void quicksort3(int *mas, int first, int last){
         int mid, count;
         int f=first, l=last;
         mid=mas[(f+l) / 2];
     do
      {
         while (mas[f]<mid) f++;
         while (mas[l]>mid) l--;
         if (f<=l)
         {
            count=mas[f];
            mas[f]=mas[l];
            mas[l]=count;
            f++;
            l--;
         }
      } while (f<l);
      if (first<l) quicksort3(mas, first, l);
      if (f<last) quicksort3(mas, f, last);
}

void quicksort_last(int *mas, int first, int last){
         int mid, count;
         int f=first, l=last;
         mid=mas[(f+l) / 2];
     do
      {
         while (mas[f]<mid) f++;
         while (mas[l]>mid) l--;
         if (f<=l)
         {
            count=mas[f];
            mas[f]=mas[l];
            mas[l]=count;
            f++;
            l--;
         }
      } while (f<l);
      if (first<l) quicksort_last(mas, first, l);
      if (f<last) quicksort_last(mas, f, last);
}

int main()
{
int n;
cin>>n;
int *A=new int[n];
cout<<"Start massive: ";
for (int i=0; i<n; i++)
   {
   cin>>A[i];
   }
first=0; last=n-1;
int res = quicksort(A, first, last);
quicksort3(A, first, res);
quicksort_last(A, res+1, last);
cout<<endl<<"Result: ";
for (int i=0; i<n; i++) cout<<A[i]<<" ";
delete []A;
system("pause>>void");
}