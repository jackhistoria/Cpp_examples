/*
Write a function that takes 3 arguments,
a length, width and height,
dynamically allocates a
3-dimensional array with those values and
fills the 3-dimensional array with multiplication tables.
Make sure to free the array when you are done.

Helped but figured the *** p_p_p_... myself
https://www.techiedelight.com/dynamic-memory-allocation-in-c-for-2d-3d-array/#3D
*/




#include <iostream>
#include <string>

using namespace std;

void set_array_size(int *p_a,int *p_b,int *p_c);
void get_array_table(int *p_a,int *p_b, int *p_c);

int main()
{
  int *p_a = new int;
  int *p_b = new int;
  int *p_c = new int;

  *p_a = 1;

    while (*p_a + *p_b + *p_c != 0)
      {

        set_array_size(p_a,p_b,p_c);
        system("clear"); //clear the terminal
        get_array_table(p_a,p_b,p_c);
      }

  delete p_a;
  p_a = nullptr; //to get an error if used later
  delete p_b;
  p_b = nullptr;
  delete p_c;
  p_c = nullptr;

  return 0;
}

void get_array_table(int *p_a, int *p_b, int *p_c)
{

    int i,j,k,l;

    //Dynamically Allocate Memory for 3D Array in C++
    int ***p_p_p_array = new int**[*p_a];

          for(i = 0; i < *p_a; i++)
            {
              p_p_p_array[i] = new int*[*p_b];

              for(j = 0; j < *p_b;j++)
                {
                    p_p_p_array[i][j] = new int[*p_c];
                }
            }

      // assign values to allocated Memory
      for ( i = 0; i < *p_a; i++)
        {
          for (j = 0; j < *p_b; j++)
          {
              for ( k = 0; k < *p_c; k++)
              {

                p_p_p_array[i][j][k] = i*j*k;
              }
          }
        }
      // print the 3D Array
      for (i = 0; i < *p_a; i++)
        {
          for ( j = 0; j < *p_b; j++)
            {
              for (k = 0; k < *p_c; k++)
                {
                  cout << p_p_p_array[i][j][k] << " ";
                    if (k == *p_c)
                      {
                        cout << endl;
                      }
                }
              cout << endl;
            }
            cout << endl;
        }

      //deallocate Memory
      for (i = 0; i < *p_a; i++)
        {
          for (j = 0; j < *p_b; j++)
            {
              delete[] p_p_p_array[i][j];
            }
            delete[] p_p_p_array[i];
        }
        delete[] p_p_p_array;

}

void set_array_size(int *p_a,int *p_b,int *p_c)
{
  cout << "Write in a: ";
  cin >> *p_a;
  cout << "Write in b: ";
  cin >> *p_b;
  cout << "Write in c: ";
  cin >> *p_c;
}
