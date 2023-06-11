#include<bits/stdc++.h>
// Includes all the header files
using namespace std;
// namespace ansh{
//   int a = 100;
//   int value(){
//     return 500;
//   }
// }
// struct node{
//     string str;
//     int a;
//     int num;
//     node(str_, a_, num_){
//         str = str_;
//         a = a_;
//         num = num_;
//     };
// };

int main(){
    // int a = 10;
    // cout<<a<<endl;
    // cout<<ansh::value()<<endl;
    // cout<<ansh::a<<endl;
    // struct node ansh;

    // // Wrong way of declaring
    // ansh.a = 100;
    // ansh.num = 100;
    // ansh.str = "learning";

    // node ansh = new node("ansh", 100, 500);

    // // containers
    // // Arrays
    // array<int, 100> arr; // {all values are garbage values} if we define globally than all the values are zeros
    // array<int, 5> arr1 = {1,3,4}; // ->{1,3,5,0,0} the indicies which are not given value is zero
    // arr1.fill(5); // fills all the indices by 5
    // arr1.at(4); // like arr[4]
    // // iterators
    // // begin() , rbegin(), end(), rend();
    // array<int, 5> arr = {1,2,3,4,5};
    // for(auto it: arr.begin(); it != arr.end(); it++){
    //     cout<< *it <<" ";
    // }
    // // for each loop
    // for(auto it: arr){
    //     cout<<it<<" ";
    // }
    // // some basic functions
    // cout<< arr.size()<<endl;
    // cout<< arr.front()<<endl;
    // cout<< arr.back()<<endl;


    // // Vector -> Dynamic array
    // vector <int> arr; // intially the size is zero {}->empty vector
    // arr.push_back(0); // pushes the variable behind
    // arr.push_back(1);

    // arr.pop_back(); // removes the element from behind

    // arr.clear();  // removes all the elements

    // vector<int> vec(4, 0); // -> {0,0,0,0}
    
    // // to copy the entire vector
    // vector<int> vec2(v.begin(), v.end());  //[ )
    // vector<int> vec3(vec);

    // vector<int>ansh;
    // ansh.push_back(1);
    // ansh.push_back(3);
    // ansh.push_back(4);
    // // if i wanat to copy first two elements of the vector in other vector then 

    // vector<int> vec4(ansh.begin(),ansh.begin() + 2)  // [ )  ->{1,2}

    // // emplace_back is same as push_back but takes less time

    vector<vector<int>> vec;

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);

    vector<int> brr;
    brr.push_back(10);
    brr.push_back(20);
    brr.push_back(30);

    vec.push_back(arr);
    vec.push_back(brr);

    for(auto it:vec){
        for(auto it2: it){
             cout<<it2<<" ";
        }
    }
    cout<<endl;

    for(int i=0; i<vec.size();i++){
        for(int j=0; j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}