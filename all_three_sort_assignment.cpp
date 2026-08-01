#include <iostream>
using namespace std ;
struct student {
string name ;
int roll_no;
float CGPA;
};
void bubble_sort (student s[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (s[j+1].roll_no<s[j].roll_no) {
                swap(s[j+1],s[j]);
            }
        }
    }
}
void selection_sort (student s[],int n){
for (int i=0;i<n-1;i++){
    int min =i;
    for (int j=i+1;j<n;j++){
if (s[j].CGPA<s[min].CGPA){
    min = j;
}

    }
    swap (s[i],s[min]);
}
}
void insertion_sort(student s[],int n){
    for (int i=0;i<n;i++){
        int j=i;
        while (j>0 && s[j-1].name>s[j].name) {
    swap (s[j-1],s[j]);
    j--;
        }
    }
}
int partition (student s[], int low, int high){
    int i=low; 
    int j= high; 
    float pivot =s[low].CGPA;
    while (i<j){
        while (s[i].CGPA<= pivot && i<=high-1){
            i++;
        }
        while (s[j].CGPA>pivot && j>=low+1){
            j--;
        }
        if (i<j){
            swap(s[i],s[j]);
        }
    }
    swap(s[low], s[j]);
    return j;
}

void quick_sort(student s[], int low, int high)
{
    if (low < high)
    {
        int p = partition(s, low, high);

        quick_sort(s, low, p - 1);
        quick_sort(s, p + 1, high);
    }
}

int main () {
    int n;
    cin>>n;
    struct student s[n];
    for (int i=0;i<n;i++){
        cout<<"enter the name of student:"<<endl;
        cin>>s[i].name;
        cout<<"enter the roll num :"<<endl;
        cin>>s[i].roll_no;
        cout<<"enter the cgpa :"<<endl;
        cin>>s[i].CGPA;
    }
    int fx;
    cout<<"enter 1 if want bubble(roll num) sort enter 2 if want selection sort(cgpa) and 3 if want insertion sort(name) & 4 if want topper n cgpa sorted :\n";
    cin>>fx;
    switch(fx){

case 1:
    bubble_sort(s,n);
    break;

case 2:
    selection_sort(s,n);
    break;

case 3:
    insertion_sort(s,n);
    break;
case 4:
    quick_sort(s, 0, n - 1);
    break;

default:
    cout<<"Invalid input";
}
    
    
   
    for (int i=0;i<n;i++){
        if (fx==1){
       cout<<s[i].roll_no<<" ";
        }
        else if (fx==2){
            cout<<s[i].CGPA<<" ";
        }
        else if (fx==3){
        cout<<s[i].name<<" ";
        }
        
    }
    if (fx==4){
            cout<<"the soted cgpa :"<<endl;
            for (int i=0;i<n;i++){
            cout<<s[i].CGPA<<endl;
            }
            cout<<"the topers are:"<<endl;
            for (int i=0;i<10 && i<n;i++){
                cout<<"name :"<<s[n-i-1].name<<"\n"<<" roll no:"<<s[n-i-1].roll_no<<"\n"<<" cgpa:"<<s[n-i-1].CGPA<<"\n ";
            }
        }
   
return 0;
}