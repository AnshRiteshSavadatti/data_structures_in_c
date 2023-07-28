// //   STRUCTURES in collage // // 
// #include<Stdio.h>
// #include<Stdio.h>

// void display(char name[], int centuries, int total_runs, int fifties){
//     printf("%s\n",name);
//     printf("%d\n",centuries);
//     printf("%d\n",total_runs);
//     printf("%d\n",fifties);
// }
// int main(){
//     typedef struct criketer{
//         char name[20];
//         int centuries;
//         int total_runs;
//         int fifties;
//     }c;
//     c c1;
//     printf("Enter the name ");
//     gets(c1.name);
//     printf("Enter the number of centuries ");
//     scanf("%d",&c1.centuries);
//     printf("Enter total runs ");
//     scanf("%d",&c1.total_runs);
//     printf("Enter the fifties");
//     scanf("%d",&c1.fifties);

//   display(c1.name,c1.centuries,c1.fifties,c1.total_runs);
//     // printf("%s\n",c1.name);
//     // printf("%d\n",c1.centuries);
//     // printf("%d\n",c1.total_runs);
//     // printf("%d\n",c1.fifties);
//   return 0;
// }



// passing structures in functions
// #include<stdio.h>
// #include<stdlib.h>
// #include<strings.h>
// struct student_ID{
//    char name[20];
//    char usn[15];
//    int rollno;
//    int sem;
//   }s;

// struct student_ID read_structure(struct student_ID s){
//   printf("Enter the name ");
//   gets(s.name);
//   printf("Enter the USN ");
//   scanf("%s",s.usn);
//   printf("Enter the roll number ");
//   scanf("%d",&s.rollno);
//   printf("Enter the semester ");
//   scanf("%d",&s.sem);
//   return s;
// }

// void display_structure(struct student_ID s){
//   puts(s.name);
//   printf("%s\n",s.usn);
//   printf("%d\n",s.rollno);
//   printf("%d\n",s.sem);
// }

// int main(){
//   s = read_structure(s);
//   display_structure(s);
// return 0;
// }


// // Arrays in structures
// #include<stdio.h>
// #include<stdlib.h>
// #include<strings.h>
// struct student_ID{
//    char name[20];
//    char usn[15];
//    int rollno;
//    int sem;
//   }s[20];

// void  read_structure(struct student_ID s[], int n){
//   for(int i=0; i<n; i++){
//   printf("Enter the name ");
//   scanf("%s",s[i].name);
//   printf("Enter the USN ");
//   scanf("%s",s[i].usn);
//   printf("Enter the roll number ");
//   scanf("%d",&s[i].rollno);
//   printf("Enter the semester ");
//   scanf("%d",&s[i].sem);
//   }
// }

// void display_structure(struct student_ID s[], int n){
//   for(int i=0; i<n; i++){
//   puts(s[i].name);
//   printf("%s\n",s[i].usn);
//   printf("%d\n",s[i].rollno);
//   printf("%d\n",s[i].sem);
//   }
// }

// int main(){
//   int n;
//   printf("Enter the number of students ");
//   scanf("%d",&n);
//   //for(int i=0; i<n; i++){
//   read_structure(s,n);
//   display_structure(s,n);
//   //}
// return 0;
// }



// // Pointers in structures
// #include<stdio.h>
// #include<stdlib.h>
// #include<strings.h>
// struct student_ID{
//    char name[20];
//    char usn[15];
//    int rollno;
//    int sem;
//   }s;

//   void  read_structure(struct student_ID *s1){
//   printf("Enter the name ");
//   scanf("%s",s1->name);
//   printf("Enter the USN ");
//   scanf("%s",s1->usn);
//   printf("Enter the roll number ");
//   scanf("%d",&s1->rollno);
//   printf("Enter the semester ");
//   scanf("%d",&s1->sem);
// }

// void display_structure(struct student_ID *s1){
//   puts(s1->name);
//   printf("%s\n",s1->usn);
//   printf("%d\n",s1->rollno);
//   printf("%d\n",s1->sem);
// }

// int main(){
//   struct student_ID *s1;
//   s1 =&s; 
//   read_structure(s1);
//   display_structure(s1);
// return 0;
// }





// Pointers in structures in arrays
// #include<stdio.h>
// #include<stdlib.h>
// #include<strings.h>
// struct student_ID{
//    char name[20];
//    char usn[15];
//    int rollno;
//    int sem;
//   }s[5];

//   void  read_structure(struct student_ID *s1, int n){
//     for(int i=0; i<n; i++){
//   printf("Enter the name ");
//   scanf("%s",s1->name);
//   printf("Enter the USN ");
//   scanf("%s",s1->usn);
//   printf("Enter the roll number ");
//   scanf("%d",&s1->rollno);
//   printf("Enter the semester ");
//   scanf("%d",&s1->sem);
//   s1++;
//     }
// }

// void display_structure(struct student_ID *s1, int n){
//   for(int i=0; i<n; i++){
//   puts(s1->name);
//   printf("%s\n",s1->usn);
//   printf("%d\n",s1->rollno);
//   printf("%d\n",s1->sem);
//   s1++;
//   }
// }

// int main(){
//   struct student_ID *s1;
//   s1 = s; 
//   struct student_ID *s2;
//   int n;
//   printf("Enter the number of students ");
//   scanf("%d",&n);
//   read_structure(s1,n);
//   display_structure(s1,n);
// return 0;
// }




// searching a structure in a array of structures
// #include<Stdio.h>
// #include<string.h>

// typedef struct student_id{
//   char name[20];
//   char usn[15];
//   int rollno;
//   int sem;
// }s;
// s st[5];// struct student_id st[5]

// void read(s* s1, int n){
//   for(int i=0; i<n; i++){
//     printf("Enter the student name ");
//     scanf("%s",s1->name);
//     printf("Enter the usn ");
//     scanf("%s",s1->usn);
//     printf("Enter the rollno ");
//     scanf("%d",&s1->rollno);
//     printf("Enter the sem ");
//     scanf("%d",&s1->sem);
//     s1++;
//   }
// }

// void print(s* s1, int n){
//   for(int i=0; i<n; i++){
//     printf("%s\n",s1->name);
//     printf("%s\n",s1->usn);
//     printf("%d\n",s1->rollno);
//     printf("%d\n",s1->sem);
//     s1++;
//   }
// }

// void search(s* s1, int n){
//   for(int i=0; i<n; i++){
//     if(!strcmp("ansh",s1->name)){
//    // if(s1->rollno == 9){
//       printf("%s\n",s1->name);
//       printf("%s\n",s1->usn);
//       printf("%d\n",s1->rollno);
//       printf("%d\n",s1->sem);
//     }
//     s1++;
//   }
// }
// int main(){
//   int n;
//   printf("Enter the number the students ");
//   scanf("%d",&n);
//   s * s1;
//   s1 = st;
//   read(s1, n);
//   print(s1, n);
//   search(s1, n);
//   return 0;
//   }





// // Using dynamic memory allocation in structures
// // fflush(stdin);
// #include<Stdio.h>
// #include<stdlib.h>
// #include<string.h>
// typedef struct student{
//     char name[20];
//     char USN[20];
//     int roll;
// }s;

// void read(s *s1, int n){
//     for(int i=0; i<n; i++){
//     printf("Enter the name ");
//     scanf("%s",s1->name);
//     printf("Enter the USN ");
//     scanf("%s",s1->USN);
//     printf("Enter the roll no ");
//     scanf("%d",&s1->roll);
//     s1++;
//     }
// }



// void print(s *s1, int n){
//     for(int i=0; i<n; i++){
//     printf("%s\n",s1->name);
//     printf("%s\n",s1->USN);
//     printf("%d\n",s1->roll);
//     s1++;
//     }
// }
// void rollno(s* s1, int n){
//     int m;
//     char u[20];
//     printf("Enter the no of usn");
//     scanf("%d",&m);
//     for(int i=0; i<m; i++){
//         printf("Enter the USN");
//         scanf("%s",u);
    
//         for(int k=0; k<n; k++){
//             int j = strcmp(u, (s1+k)->USN );
//             if(j == 0){
//                printf("%s\n",(s1+k)->name);
//                printf("%s\n",(s1+k)->USN);
//                printf("%d\n",(s1+k)->roll);
                
//             }
           

//             // else{
//             //  printf("USN not found");
//             // }
//         }
        
//     }
// }

// int main(){
// int n;
// s *s1;
// printf("Enter the number of students ");
// scanf("%d",&n);
// s1 = (s*)malloc(n*sizeof(s));
// read(s1, n);
// print(s1, n);
// rollno(s1, n);
// free(s1);
// }
 




 // appolo hospital 

// #include<Stdio.h>
// #include<stdlib.>
// #include<string.h>

// typedef struct information{
//     char name[20];
//     char ID[20];
//     char blood_group[10];
//     int room_no;
//     int bill;
// }I;

// void read(I* ptr, int n){
//     for(int =0; i<n; i++){
//         printf("Enter the name");
//         gets((ptr+i)->name);
//         printf("Enter the ID");
//         gets((ptr+i)->ID);
//         printf("Enter the blood group ");
//         gets((ptr+i)->blood_group);
//     }
// }



// #include<Stdio.h>
// #include<stdlib.>
// #include<string.h>
// typedef struct orders{
//     //(ptr+i)->fooditem[j]
//     int number;
//     char name[20];
//     char address[20];
//     int phone;
//     int iteams;
//     char iteam[20][200];
// }i;

// int main(){
//     //int n; // item
//     //i *ptr;
//     int m; // customers
//     printf("Enter the number of customers ");
//     scanf("%d",&m);
//    for(int i=0; i<m; i++){
//     for(int i=0; i<n; i++){
//     printf("Enter the iteams");
    
    
//     }
//    }
    

// }


// // class test problem
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// typedef struct information{
//     int age;
//     int salary;
//     float exp;
//     char name[20];
//     char employee_ID[20];
// }inf;

// void read(inf *ptr, int n){
//     for(int i=0; i<n; i++){
//     printf("Enter the age ");
//     scanf("%d",&ptr->age);
//     printf("Enter the salary");
//     scanf("%d",&ptr->salary);
//     printf("Enter the experiance");
//     scanf("%f",&ptr->exp);
//     printf("Enter the name");
//     scanf("%s",ptr->name);
//     printf("Enter the employee_id");
//     scanf("%s",ptr->employee_ID);
//     ptr++;
//     }
// }

// void display(inf * ptr, int n){
//     for(int i=0; i<n; i++){
//     printf("%d\n",ptr->age);
//     printf("%d\n",ptr->salary);
//     printf("%f\n",ptr->exp);
//     printf("%s\n",ptr->name);
//     printf("%s\n",ptr->employee_ID);
//     printf("\n");
//     ptr++;
//     }
// }

// void sort(inf * ptr, int n){
//    for (int i = 0; i < n-1; i++)
//    {
//     for (int j = 0; j < n-1-i; j++)
//     {
//         if((ptr+j)->exp > (ptr+j+1)->exp){
//             inf temp = *(ptr+j);
//             *(ptr+j) = *(ptr+j+1);
//             *(ptr+j+1) = temp;
//         }
//     }
    
//    }
   
// }

// void bonus(inf* ptr ,int n){
//     for(int i=0; i<n; i++){
//         if(ptr->exp >= 10){
//             ptr->salary += (0.1*ptr->salary);
//         }
//         ptr++;
//     }
// }

// int main(){
//     int n; 
//     printf("Enter the value of n");
//     scanf("%d",&n);
//     inf *ptr;
//     ptr = (inf*)malloc(n*sizeof(inf));
//     read(ptr, n);
//     display(ptr,n);
//     sort(ptr, n);
//     display(ptr,n);
//     bonus(ptr,n);
//     display(ptr,n);
//     return 0;
// }





// Nested structures 

// #include<Stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct marks{
//     int marks;
// };

// struct student{
//     char name[20];
//     int rollno;
//     struct marks m;
// };

// struct student read(struct student s){
//     scanf("%s%d%d",s.name,&s.rollno,&s.m.marks);
//     return s;
// }

// void display(struct student s){
//     printf("%s\n%d\n%d\n",s.name,s.rollno,s.m.marks);
// }


// int main(){
//  struct student s;
//  s = read(s);
//  display(s);
//  return 0;
// }



// // Nested structures with arrays 

// #include<Stdio.h>
// #include<stdlib.h> 
// #include<string.h>

// struct marks{
//     int marks[5];
// };

// struct student{
//     char name[20];
//     int rollno;
//     struct marks m;
// };

// void read(struct student s[], int n){
//     for(int i=0; i<n; i++){
//     scanf("%s%d",s[i].name,&s[i].rollno);
//     for(int j=0; j<5; j++){
//     printf("enter the marks %d",j+1);
//     scanf("%d",&s[i].m.marks[j]);
//     }
//   }
// }

// void display(struct student s[], int n){
//     for(int i=0; i<n; i++){
//     printf("%s\n%d\n",s[i].name,s[i].rollno);
//     for(int j=0; j<5; j++){
//         printf("%d\n",s[i].m.marks[j]);
//     }
//     }

// }

// int main(){
// int n;
// printf("Enter the number of students ");
// scanf("%d",&n);
// struct student s[n];
// read(s,n);
// display(s,n);
// return 0;
// }




// // cab question

// #include<stdio.h>
// #include<Stdlib.h>
// #include<string.h>


// typedef struct cab_details{
//     char name[15];
//     char pickup[15];
//     char drop[15];
//     int phoneno;
//     int travel_time;
//     float bill;
//     float distance;
// }inf;

// void read(inf* ptr, int n){
//     for(int i=0; i<n; i++){
//         printf("Enter the name ");
//         scanf("%s",(ptr+i)->name);
//         printf("Enter the pick up location ");
//         scanf("%s",(ptr+i)->pickup);
//         printf("Enter the drop location ");
//         scanf("%s",(ptr+i)->drop);
//         printf("Enter the phone number ");
//         scanf("%d",&(ptr+i)->phoneno);
//         printf("Enter the travel time ie the number of times you travelled in same taxi ");
//         scanf("%d",&(ptr+i)->travel_time);
//         printf("Enter the distance ");
//         scanf("%f",&(ptr+i)->distance);
//     }
// }


// void display(inf* ptr, int n){
//     for(int i=0; i<n; i++){
//        printf("\n");
//         printf("%s\n",(ptr+i)->name);
//         printf("%s\n",(ptr+i)->pickup);
//         printf("%s\n",(ptr+i)->drop);
//         printf("%d\n",(ptr+i)->phoneno);
//         printf("%d\n",(ptr+i)->travel_time);
//     }
// }


// void same_place(inf* ptr, int n){
//     printf("The travelers travelling from same location are ");
//     for(int i=0; i<n-1; i++){
//         for(int j=1; j<n; j++){
//             int k = strcmp((ptr+i)->pickup,(ptr+j)->pickup);
//             if(k == 0){
//                 printf("%s\n",(ptr+i)->name);
//                 printf("%d\n",(ptr+i)->phoneno);
                   
//             }
//         }
//          printf("\n");
//     }
// }


// void bill(inf* ptr, int n){
//     for(int i=0; i<n; i++){
//         (ptr +i)->bill= 10 *(ptr+i)->distance;
//         if((ptr+i)->travel_time != 10){
//             printf("%s\n",(ptr+i)->name);
//             printf("%f : is the bill \n",(ptr+i)->bill);
//         }
//         if((ptr+i)->travel_time == 10){
//              printf("%s\n",(ptr+i)->name);
//             printf("Your current bill is 0 \n");
//         }
//     }
// }

// int main(){
//     int n;
//     printf("Enter the value of n ");
//     scanf("%d",&n);
//     inf* ptr;
//     ptr = (inf*)malloc(n*sizeof(inf));
//     read(ptr,n);
//     display(ptr,n);
//     same_place(ptr,n);
//     bill(ptr,n);
//     return 0;
// }





// // train question
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// struct train{

// char name[20];
// char address[20];
// int age;
// char bill[20];
// char destination[20];
// float price;
// };
// void read(struct train*p,int n);
// void display(struct train *p,int n);
// void payment(struct train*p,int n);
// void count(struct train*p,int n);
// int main()
// {
//  struct train s[100],*p;
// int n;
// p=s;
// printf("No of passengers are:");
// scanf("%d",&n);
//  p=(struct train*)malloc(n*sizeof(struct train));
//     read(p,n);
//     display(p,n);
//     payment(p,n);
//     count(p,n);
//     free(p);
// }
// void read(struct train*p,int n){
// for(int i=0;i<n;i++)
// {
//     scanf("%s%s%d%s%s%d",(p+i)->name,(p+i)->address,&(p+i)->age,(p+i)->bill,(p+i)->destination,&(p+i)->price);
// }
// }
// void display(struct train *p,int n){

// for(int i=0;i<n;i++)
// {
//     printf("%s\n%s\n%d\n%s\n%s\n",(p+i)->name,(p+i)->address,(p+i)->age,(p+i)->bill,(p+i)->destination,(p+i)->price);
// }
// }
// void payment(struct train*p,int n){
// int k;
// for(int i=0;i<n;i++){
//     k=strcmp((p+i)->bill,"UPI");


// for(int j=0;j<n;j++){
//     if(k==0){
//         ((p+i)->price)=((p+i)->price)-0.30*((p+i)->price);
//     }
// }
// }

// for(int i=0;i<n;i++)
// {
//     printf("%s\n%s\n%d\n%s\n%s\n",(p+i)->name,(p+i)->address,(p+i)->age,(p+i)->bill,(p+i)->destination,(p+i)->price);
// }

// }
// void count(struct train*p,int n){
// int count =0,j;
// for(int i=0;i<n;i++){
//     j=strcmp((p+i)->destination,"dharwad");

//     if(j==0){
//         count++;
//     }
// }
// printf("%d",count);
// }




// the cricketer question
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<math.h>
// typedef struct details_of_player
// {
//     char name[20];
//     char team[20];
//     int centuries;
//     int odi_rank;
//     int runs;

// }dp;

// void read(dp *s , int n)
// {
//     for (int i=0;i<n;i++)
//     {
//         printf("Enter the name of player");
//         scanf("%s",s->name);
//         printf("Enter the team ");
//         scanf("%s",s->team);
//         printf("Enter the no of centuries");
//         scanf("%d",&s->centuries);
//         printf("Enter the odi rank");
//         scanf("%d",&s->odi_rank);
//         printf("Enter the runs ");
//         scanf("%d",&s->runs);
//         s++;
//     }
    
// }
// void display(dp *s,int n)
// {
//      for (int i=0;i<n;i++)
//     {
//         printf("%s\n",s->name);
//         printf("%s\n",s->team);
//         printf("%d\n",s->centuries);
//         printf("%d\n",s->odi_rank);
//         printf("%d\n",s->runs);
//          s++;
//     }
   
// }


//  void sort (dp *s, int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=0; j<n-1-i; j++){
//             if((s+j)->runs <(s+j+1)->runs ){
//                 dp temp = *(s+j);
//                 *(s+j) = *(s+j+1);
//                 *(s+j+1) = temp;
//             }
//         }
//     }
//  }


//  void serach (dp *s, int n)
//  {
//      char namee[15];
//  printf("Enter the name");
//  scanf("%s",namee);

//      for(int i=0;i<n;i++)
//      {
//          int j=strcmp(namee,(s+i)->name);
//          if(j==0)
//          {
//         printf("%s\n",(s+i)->name);
//         printf("%s\n",(s+i)->team);
//         printf("%d\n",(s+i)->centuries);
//         printf("%d\n",(s+i)->odi_rank);
//         printf("%d\n",(s+i)->runs);
//          }
//      }
//  }
//  int main()
//  {
//      int n,temp;
//      printf("Enter the no of players");
//      scanf("%d",&n);
//      struct  details_of_player (*s);
//      s=(struct  details_of_player *)malloc(n*sizeof(struct details_of_player));
//      read(s,n);
//      display(s,n);
//      sort(s,n);
//      display(s,n);
//      serach(s,n);
//      return 0;

//  }






// //BRTS question

// #include<Stdio.h>
// #include<Stdlib.h>
// #include<string.h>

//  typedef struct bus_details{
//     int busno;
//     char sourceplace[15];
//     char destination[15];
//     float timingsdep;
//     float timingsreach;
// }inf;

// void read(inf* ptr, int n){
//     for(int i=0; i<n; i++){
//     printf("Enter the bus number ");
//     scanf("%d",&(ptr+i)->busno);
//     printf("Enter the source place ");
//     scanf("%s",(ptr+i)->sourceplace);
//     printf("Enter the destination ");
//     scanf("%s",(ptr+i)->destination);
//     printf("Enter the depature timings ");
//     scanf("%f",&(ptr+i)->timingsdep);
//     printf("Enter the reaching timings ");
//     scanf("%f",&(ptr+i)->timingsreach);
//     }
// }

// void display(inf* ptr, int n){
//     for(int i=0; i<n; i++){
//     printf("%d\n",(ptr+i)->busno);
//     printf("%s\n",(ptr+i)->sourceplace);
//     printf("%s\n",(ptr+i)->destination);
//     printf("%f\n",(ptr+i)->timingsdep);
//     printf("%f\n",(ptr+i)->timingsreach);
//     }
// }

// void sort(inf* ptr, int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=0; j<n-1-i; j++){
//             if((ptr+j)->busno > (ptr+j+1)->busno){
//                 inf temp = *(ptr+j);
//                 *(ptr+j) = *(ptr+j+1);
//                 *(ptr+j+1) = temp;
//             }
//         }

//     }
// }


// void search(inf* ptr, int n){
//     int no;
//     printf("Enter the  number which is to be searched ");
//     scanf("%d",&no);
//     for(int i=0; i<n; i++){
//         if(no == (ptr+i)->busno){
//             printf("%d\n",(ptr+i)->busno);
//             printf("%s\n",(ptr+i)->sourceplace);
//             printf("%s\n",(ptr+i)->destination);
//             printf("%f\n",(ptr+i)->timingsdep);
//             printf("%f\n",(ptr+i)->timingsreach);
//         }
//     }
// }

// int main(){
//     int n;
//     printf("Enter the value of n ");
//     scanf("%d",&n);
//     inf *ptr;
//     ptr = (inf*)malloc(n*sizeof(inf));
//     read(ptr,n);
//     display(ptr,n);
//     sort(ptr,n);
//     display(ptr,n);
//     search(ptr,n);
//     return 0;
// }




// #include<stdio.h>
// #include<Stdlib.h>
// #include<string.h>


//  struct brts{
//     int busno;
//     char source[20];
//     char destination[20];
//     float departure;
//     float reach;
// };
// void read(struct brts*p,int n);
// void display(struct brts*p,int n);
// void sort(struct brts*p,int n);
// void search(struct brts*p,int n,int key);
// int main()
// {
//     int n;
//     printf("the value of n is:");
//     scanf("%d",&n);
//     int key;
//     printf("the value of key is");
//     scanf("%d",&key);
//     struct brts s[100],*p;
//     p=s;
//     p=(struct brts*)malloc(n*sizeof(struct brts));
//     read(p,n);
//     display(p,n);
//     sort(p,n);
//     printf("\n\n");
//     display(p,n);
//     search(p,n,key);

// }
// void read(struct brts*p,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         printf("bus no. is:");
//         scanf("%d",&(p+i)->busno);
//         printf("source is:");
//         scanf("%s",(p+i)->source);
//         printf("destination is:");
//         scanf("%s",(p+i)->destination);
//         printf("departure time is");
//         scanf("%f",&(p+i)->departure);
//         printf("reaching time is:");
//         scanf("%f",&(p+i)->reach);

//     }
// }
// void display(struct brts*p,int n){

// for(int i=0;i<n;i++)
//     {

//         printf("%d\n",(p+i)->busno);

//         printf("%s\n",(p+i)->source);

//         printf("%s\n",(p+i)->destination);

//         printf("%f\n",(p+i)->departure);

//         printf("%f\n",(p+i)->reach);

//     }

// }
// void sort(struct brts*p,int n)
// { struct brts temp;
//     for(int i=0;i<=n-1;i++)
//     {
//         for(int j=0;j<=n-i-1;j++)
//         {
//             if(((p+j)->busno)>((p+j+1)->busno)){
//                  temp = *(p+j);
//                 *(p+j) = *(p+j+1);
//                 *(p+j+1) = temp;
//             }
//         }

//     }
//    for(int i=0;i<n;i++)
//     {

//         printf("%d\n",(p+i)->busno);

//         printf("%s\n",(p+i)->source);

//         printf("%s\n",(p+i)->destination);

//         printf("%f\n",(p+i)->departure);

//         printf("%f\n",(p+i)->reach);

//     }

// }
// void search(struct brts*p,int n,int key)
// {
//      for(int i=0;i<n;i++)
//      {
//          if((p+i)->busno==key){
//             printf("This is the bus");
        
//           printf("%d\n",(p+i)->busno);

//         printf("%s\n",(p+i)->source);

//         printf("%s\n",(p+i)->destination);

//         printf("%f\n",(p+i)->departure);

//         printf("%f\n",(p+i)->reach);
//          }

//      }
// }




// //movie quesion
// #include<Stdio.h>
// #include<Stdlib.h>
// #include<string.h>

// typedef struct movie_details{
//     char movie_name[15];
//     char producer[15];
//     char director[15];
//     int release_year;
//     char production_house[15];
// }inf;

// void read(inf* ptr, int n){
//     for(int i=0; i<n; i++){
//         printf("Enter the name ");
//         scanf("%s",(ptr+i)->movie_name);
//         printf("Enter the producer name ");
//         scanf("%s",(ptr+i)->producer);
//         printf("Enter the director name ");
//         scanf("%s",(ptr+i)->director);
//         printf("Enter the release year ");
//         scanf("%d",&(ptr+i)->release_year);
//         printf("Enter the production house name ");
//         scanf("%s",(ptr+i)->production_house);
//     }
// }


// void display(inf* ptr, int n){
//     for(int i=0; i<n; i++){
//         printf("%s\n",(ptr+i)->movie_name);
//         printf("%s\n",(ptr+i)->producer);
//         printf("%s\n",(ptr+i)->director);
//         printf("%d\n",(ptr+i)->release_year);
//         printf("%s\n",(ptr+i)->production_house);
//     }
// }

// void sort(inf* ptr, int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=0; j<n-i-1; j++){
//             if((ptr+j)->release_year > (ptr+j+1)->release_year){
//                 inf temp = *(ptr+j);
//                 *(ptr+j) = *(ptr+j+1);
//                 *(ptr+j+1) = temp;
//             }
//         }
//     }
// }


// void director(inf* ptr, int n, char name[20]){
    
//     for(int i=0; i<n; i++){
//         printf("\n");
//         int k = strcmp(name, (ptr+i)->director);
//             if(k == 0){
//                 printf("%s\n",(ptr+i)->movie_name);
//                 printf("%s\n",(ptr+i)->producer);
//                 printf("%s\n",(ptr+i)->director);
//                 printf("%d\n",(ptr+i)->release_year);
//                 printf("%s\n",(ptr+i)->production_house);
//             }
        
//     }
// }


// void production_house(inf* ptr, int n){
//     char name[15];
//     printf("Enter the d name producer_house name ");
//     scanf("%s",name);
//     for(int i=0; i<n; i++){
//         printf("\n");
//         int k = strcmp(name, (ptr+i)->production_house);
//             if(k == 0){
//                 printf("%s\n",(ptr+i)->movie_name);
//                 printf("%s\n",(ptr+i)->producer);
//                 printf("%s\n",(ptr+i)->director);
//                 printf("%d\n",(ptr+i)->release_year);
//                 printf("%s\n",(ptr+i)->production_house);

//             }
//     }
// }

// int main(){
//     int n;
//     printf("Enter the number of movies ");
//     scanf("%d",&n);
//     inf * ptr;
//     ptr = (inf*)malloc(n*sizeof(inf));
//     char name[15];
//     printf("Enter the directors name ");
//     scanf("%s",name);
//     read(ptr,n);
//     display(ptr,n);
//     sort(ptr,n);
//     printf("\n\n");
//     display(ptr,n);
//     director(ptr,n,name);
//     production_house(ptr,n);
//     return 0;
// }




// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// typedef struct movie{
// char name[20];
// char producer[20];
// char director[20];
// int ryear;
// char house[20];
// }mov;
// void read(mov *p,int n);
// void sort(mov *p,int n);
// void display(mov *p,int n);
// void disdirector(mov *p,int n);
// void dishouse(mov *p,int n);
// int main()
// {
//     int n;
//     printf("The no. of movies are:");
//     scanf("%d",&n);
//     mov s[100],*p;
//     p=(mov*)malloc(n*sizeof(mov));
//     read(p,n);
//     sort(p,n);
//     display(p,n);
//     disdirector(p,n);
//     dishouse(p,n);
// }

// void read(mov *p,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         printf("Name is:\n");
//         scanf("%s",(p+i)->name);
//          printf("Name of producer is:\n");
//         scanf("%s",(p+i)->producer);
//          printf("Name of director is:\n");
//         scanf("%s",(p+i)->director);
//         printf("Release year is:\n");
//         scanf("%d",&(p+i)->ryear);
//          printf("Name of production house is:\n");
//         scanf("%s",(p+i)->house);




//     }
// }
// void sort(mov *p,int n)
// {  mov temp;
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(((p+j)->ryear)>((p+j+1)->ryear))
//             {
//                 temp =*(p+j);
//                 *(p+j)=*(p+j+1);
//                 *(p+j+1)=temp;
//             }
//         }
//     }

// }
// void display(mov *p,int n)
// {
//     for(int i=0;i<n;i++)
//     {

//         printf("%s\n",(p+i)->name);

//         printf("%s\n",(p+i)->producer);
//     printf("%s\n",(p+i)->director);

//         printf("%d\n",(p+i)->ryear);

//         printf("%s\n",(p+i)->house);




//     }

// }
// void disdirector(mov *p,int n)
// {  int k;
//     for(int i=0;i<n;i++)
//     {
//         k=strcmp((p+i)->director,"sakshi");
//         for(int j=0;j<n;j++)
//         {
//             if(k==0)
//             {
//                 printf("%s\n",(p+j)->name);

//         printf("%s\n",(p+j)->producer);
//     printf("%s\n",(p+j)->director);

//         printf("%d\n",(p+j)->ryear);

//         printf("%s\n",(p+j)->house);
//             }
//         }
//     }
// }
// void dishouse(mov *p,int n)
// {
//      int l;
//     for(int i=0;i<n;i++)
//     {
//         l=strcmp((p+i)->house,"idontknow");
//         for(int j=0;j<n;j++)
//         {
//             if(l==0)
//             {
//                 printf("%s\n",(p+j)->name);

//         printf("%s\n",(p+j)->producer);
//     printf("%s\n",(p+j)->director);

//         printf("%d\n",(p+j)->ryear);

//         printf("%s\n",(p+j)->house);
//             }
//         }
//     }
// }