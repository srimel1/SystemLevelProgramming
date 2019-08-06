#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<string.h>

using namespace std;

int main(int argc, char *argv[]){

    string data[1000];
    int i,j;
    ifstream fin("input233.txt");
    if (!fin){
        cout << "Error opening file\n";
        return 0;
    }
    int count = 0;
    while(getline(fin,data[count])){
        count++;
    }
    if (argc == 1){
       int i = 0;
       int j = count - 1;
       while (i < j){
          string temp;
          temp = data[i];
          data[i] = data[j];
          data[j] = temp;
          i++;
          j--;
       }
       for (int i = 0; i<count; i++)
           cout << data[i] << endl;
    }
    else if (argc == 2){
        i = 0;
        j = count - 1;
        while (i < j){
          string temp;
          temp = data[i];
          data[i] = data[j];
          data[j] = temp;
          i++;
          j--;
        }
        if (strcmp("-c",argv[1])== 0){
           for (int i = 0; i< count; i++){
               int m = 0;
               int n = data[i].length()-1;
               while(m<n){
                  char temp = data[i][m];
                  data[i][m] = data[i][n];
                  data[i][n] = temp;
                  m++;
                  n--;
               }
               cout << data[i] << endl;
           }     
        }
        if (strcmp("-r",argv[1]) == 0){
          
           for (int i = 0; i<count; i++){
               string list[20];
               stringstream ss(data[i]);
               int count1 = 0;
               while(ss >> list[count1])
                    count1++;
               int r = 0;
               int s = count1-1;
               while(r < s){
                  string temp1 = list[r];
                  list[r] = list[s];
                  list[s] = temp1;
                  r++;
                  s--;
               }
               for (int w = 0; w<count1; w++)
                   cout << list[w] << " ";
               cout << endl;              
           }
        }     
    }
    return 0;
}