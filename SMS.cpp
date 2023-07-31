
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct node{
    int id;
    string name;
    double price;
    int quantity;
    struct node* next;
    struct node* previous;
};
struct node* head = NULL;
struct node* new_node;




void Insert_Product(int id, string name, double price, int quantity){
    
    new_node = new node;
    new_node->id = id;
    new_node->name = name;
    new_node->price = price;
    new_node->quantity = quantity;

    new_node->next = NULL;
    new_node->previous = NULL;

    if(head == NULL){
        head = new_node;
    } 
    
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->previous = temp;
    }
}




void Delete_A_Product(int id){
    
    struct node* temp = head;
     
    if(head == NULL){
        cout<<"Store inventory is empty."<<endl;
    }

    while(temp != NULL && temp->id != id){
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"Product with ID = "<< id <<" not found."<<endl;
    }

    if(temp == head){   // Deleting first node
        head = head->next;
        head->previous = NULL;
     } 
    
    else{      // Deleting from middle & from the end
        temp->previous->next = temp->next;
        if(temp->next != NULL){
            temp->next->previous = temp->previous;
        }
    }

    cout<<"Product with ID/CODE = " << id <<" has been deleted."<<endl;
    delete(temp);
}




void Update_A_Product(int id){
    
    if(head == NULL){
        cout<<"Store inventory is empty."<<endl;
    }

    struct node* temp = head;
    while(temp != NULL && temp->id != id){
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"Product with ID = "<< id <<" not found."<<endl;
    }
    
    else{
        cout<<"Enter the new name = ";
        cin>>temp->name;
        
        cout<<"Enter the new price in PKR = ";
        cin>>temp->price;
        
        cout<<"Enter the new quantity = ";
        cin>>temp->quantity;
        cout <<"Product with ID = "<< id <<" has been updated."<< endl;
    }
}




void Display_ALL_Products(){

    if(head == NULL){
        cout <<"Store inventory is empty."<<endl;
    } 
    
    else{
        struct node* temp = head;
        cout<<"\t\t *** All Products List ***"<<endl;
        cout<<"ID/CODE"<<"\tName"<<"\tPrice"<<"\tQuantity"<<endl;
            
        while(temp != NULL){
            cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->price<<"\t"<<temp->quantity<<endl;  
            temp = temp->next;
        }
    }
}




void searching_Products(int id){

    struct node* temp = head;
    int found = 0;

    if(temp == NULL){
        cout<<"Inventory is empty..."<<endl;
    }

    else{
        while(temp->next != NULL){
            if(temp->id == id){
                found++;
                cout<<temp->name<<" product has been found having id/code "<<temp->id<<endl;
                cout<<"It's details are :"<<endl;
                cout<<"\t\t *** Products ***"<<endl;
                cout<<"ID/CODE"<<"\tName"<<"\tPrice"<<"\tQuantity"<<endl;
                cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->price<<"\t"<<temp->quantity<<endl;  
                break;
            }   
            temp = temp->next;
        }

        if(found == 0){
            cout<<temp->id<<" id/code has not been found in the system"<<endl;
        }
    }
}




int main(){ 
    int id, quantity, option;
    string name;
    double price; 

    do{
      cout<<endl;
      cout<<"  ******  Welcome to the Talha Mega Store System  ******"<<endl; 
      cout<<"               Developed by Talha Khalid\n\n";
      cout<<"1. Add a Product\n";
      cout<<"2. Delete a Product\n";
      cout<<"3. Update a Product\n";
      cout<<"4. Search a Product\n";
      cout<<"5. Display All Products\n";
      cout<<"6. Exit\n";
      cout<<"Please enter the option here = ";
      cin>>option;

      switch(option){
        case 1:
        cout<<"Enter the ID/CODE of the product = ";
        cin>>id;
        
        cin.ignore();
        cout<<"Enter the name of the product = ";
        getline(cin, name);

        cout<<"Enter the price of the product in PKR = ";
        cin>>price;
        
        cout<<"Enter the quantity of the product = ";
        cin>>quantity;
        
        Insert_Product(id, name, price, quantity);
        break;


        case 2:
        cout<<"Enter the ID/CODE you want to delete = ";
        cin>>id;

        Delete_A_Product(id);
        break;    
        
    
        case 3:
        cout<<"Enter the ID/CODE of the product you want to update = ";
        cin>>id;
        Update_A_Product(id);
        break;


        case 4:
        cout<<"Enter the ID/CODE you want to search = ";
        cin>>id;
        searching_Products(id);
        break;


        case 5:
        Display_ALL_Products();
        break;


        case 6:
        cout<<"Thank you so much. Have a Lovely day bye bye :)";
        break;


        default:
        cout<<"OOPS! Invalid option. Please enter the correct option....."<<endl;
        break;
      }
    }
    while(option!=6);

    return 0;
}


