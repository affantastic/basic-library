#include <iostream>
using namespace std;
class Product{
protected:
    int prodID;
    string prodName;
    double price;
public:
    Product(int i, string n, double p){
        prodID=i;
        prodName=n;
        price=p;
}
void display(){
    cout<<"Product ID : "<<prodID<<endl;
    cout<<"Product Name : "<<prodName<<endl;
    cout<<"Product Price : $ "<<price<<endl;
}
};
class Electronics: public Product{
protected:
    string brand;
    int warrantyPeriod;
public:
    Electronics(string b, int w, int i, string n, double p):Product(i,n,p){
        brand=b;
        warrantyPeriod=w;
    }
    void display(){
        Product::display();
        cout<<"Brand : "<<brand<<endl;
        cout<<"Warranty Period : "<<warrantyPeriod<<" Yrs"<<endl;
    }
    void checkWarranty(){
        if(warrantyPeriod>0){
            cout<<"Product is under warranty for : "<<warrantyPeriod<<endl;
        }
        else if(warrantyPeriod==0){
            cout<<"Product's warranty has expired"<<endl;
        }
        else{cout<<"Product is under no warranty"<<endl;}
    }
};
class Clothing:public Product{
protected:
    char Size;
    string material;
    bool isAvailable;
public:
    Clothing(char s, string m, bool avl, int i, string n, double p):Product(i,n,p){
        Size=s;
        material=m;
        isAvailable=avl;
    }
    void getsizeAvailability(){
        if(isAvailable){
            cout<<Size<<" Size is available for "<<prodName<<endl;
        }
        else{
            cout<<Size<<" Size is not available for "<<prodName<<endl;
        }
    }
    void display(){
        Product::display();
        cout<<"Size : "<<Size<<endl;
        cout<<"Material : "<<material<<endl;
        getsizeAvailability();
    }
};
class Books:public Product{
protected:
    string author;
    string genre;
public:
    Books(string au, string g, int i, string n, double p):Product(i,n,p){
        author=au;
        genre=g;
    }
    void display(){
        Product::display();
        cout<<"Author : "<<author<<endl;
        cout<<"Genre : "<<genre<<endl;
        }
};
main(){
    Electronics laptop("Dell",1,8743,"Laptop",349.99);
    Clothing shirt('S',"Polyester",true,1217,"Jersey",8.99);
    Books novel("Charles Dickens","Fiction",247,"Great Expectations",12.99);

    cout << "Electronics Details:" << endl;
    laptop.display();
    cout << endl;
    cout << "Clothing Details:" << endl;
    shirt.display();
    cout << endl;
    cout << "Books Details:" << endl;
    novel.display();
}



