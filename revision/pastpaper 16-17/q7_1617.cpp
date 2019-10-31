#include <iostream>

using namespace std;

void flip(char c1, char c2)
{
    char  temp;
    temp=c1;
    c1=c2;
    c2=temp;
}

void selection_sort(char array[17])
{
    int pmin;
    char tv;
    for (int i=0; i < 17; i++)
    {
        pmin = i;
        for (int j=i; j < 17;j++)
        {
            if (array[j]<=array[pmin])
            {
                pmin=j;
            }
        }
        tv = array[pmin];
		array[pmin] = array[i];
		array[i] = tv;
    }
    /*char tv='A';			// temporary value
	char lv='Z';	// lowest value
	int lv_i = 0;
	
	for (int j = 0; j < 17; j++)
	{
		lv = array[j];
		for (int i = j; i < 17; i++)
		{
			if (array[i] <= lv)
			{
				lv = array[i];
				lv_i = i;
			}
		}
		tv = array[lv_i];
		array[lv_i] = array[j];
		array[j] = tv;
		
		for (int i = 0; i<17; i++)
			cout << array[i];
		cout << endl;
	}*/
}

void insertion_sort(char a[17])
{
    char temp[17];
    for(int i=1; i < 17; i++){temp[i]=a[i];}
    int z;
    for (int i=1; i < 17; i++)
    {
        z=0;
        while ( i-z>=0 && a[i]<a[i-z])
        {
            z++;
           if (i-z>=0 && a[i]>a[i-z])
           {
               a[i-z+1]=a[i];
                for (int j=i-z+1;j<i;j++)
                {
                    a[j]=temp[j+1];
                }
           }
           
        }
        for(int i=1; i < 17; i++){temp[i]=a[i];}
    }
        
}

void printarray(char a[17])
{
    for (int i=0; i<17; i++)
    {
        cout << "'"<<a[i]<<"',";
    }
    cout << endl;
}

int main()
{
    char array1[17] =
    {'E','X','A','M','Q','U','E','S','T','I','O','N','S','E','V','E','N'};
    char array2[17] =
    {'E','X','A','M','Q','U','E','S','T','I','O','N','S','E','V','E','N'};
    //part A
    selection_sort(array1);
    printarray(array1);

    //Part B
    insertion_sort(array2);
    printarray(array2);


    return 0;
}