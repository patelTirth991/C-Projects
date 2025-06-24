/////Q-1/////

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int publishedYear;

public:
    Book(string t, string a, int year) : title(t), author(a), publishedYear(year) {}
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    int getPublishedYear() const {
        return publishedYear;
    }
};

int main() {
    Book books[] = {
        Book("Rick Dad Poor Dad", "XYZ", 1949),
        Book("To Kill a Mockingbird", "xyz", 1960),
    };
    for (int i = 0; i < 2; ++i) {
        cout << "Book " << i+1 << ":\n";
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Published Year: " << books[i].getPublishedYear() << endl;
    }
    return 0;
}

////Q-2////

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;

public:
    Person(string n, int a, string addr) {
        name = n;
        age = a;
        address = addr;
    }

    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    string getAddress() const {
        return address;
    }
    void setName(string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    void setAddress(string addr) {
        address = addr;
    }
    void display() const {
        cout << "Name: " << name << "\nAge: " << age << "\nAddress: " << address << endl;
    }
};

int main() {
    int N;
    cout << "Enter number of persons: ";
    cin >> N;
    Person* persons = new Person[N];  

    for (int i = 0; i < N; ++i) {
        string name, address;
        int age;

        cout << "\nEnter details for person " << i + 1 << ":\n";
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cin.ignore();
        cout << "Address: ";
        getline(cin, address);

        persons[i] = Person(name, age, address);
    }
    cout << "\n--- Person Details ---\n";
    for (int i = 0; i < N; ++i) {
        cout << "\nPerson " << i + 1 << ":\n";
        persons[i].display();
    }
    delete[] persons;

    return 0;
}


////Q-3////

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    string sound;

public:
    void setName(const string& n) {
        name = n;
    }

    void setSound(const string& s) {
        sound = s;
    }

    string getName() const {
        return name;
    }

    string getSound() const {
        return sound;
    }

    virtual void makeSound() const {
        cout << "This animal makes a sound: " << sound << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string& n) {
        setName(n);
        setSound("Bark");
    }

    void makeSound() const override {
        cout << getName() << " says: " << getSound() << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string& n) {
        setName(n);
        setSound("Meow");
    }

    void makeSound() const override {
        cout << getName() << " says: " << getSound() << endl;
    }
};

int main() {
    Dog dog("Dog");
    Cat cat("Cat");

    dog.makeSound(); 
    cat.makeSound(); 
    return 0;
}


////Q-4////
[Not-Done]

////Q-5////

#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex num1(5, 10);  
    Complex num2(2, 7); 

    cout << "Complex Number 1: ";
    num1.display();

    cout << "Complex Number 2: ";
    num2.display();
    Complex result = num1 - num2;

    cout << "Result of subtraction: ";
    result.display();

    return 0;
}

////Q-6////
[Not-Done]

////Q-7////

#include <iostream>

using namespace std;

class Shape {
public:
  
    virtual double area() const = 0; 
    virtual void draw() const = 0;   
    virtual ~Shape() {} 
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;  
    }

    void draw() const override {
        cout << "Drawing a Circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
   
    Rectangle(double w, double h) : width(w), height(h) {}

   
    double area() const override {
        return width * height; 
    }

    void draw() const override {
        cout << "Drawing a Rectangle with width " << width << " and height " << height << endl;
    }
};

int main() {
   
    Circle circle(10.0);    
    Rectangle rectangle(5.0, 10.0); 

    Shape* shapes[2];
    shapes[0] = &circle;     
    shapes[1] = &rectangle;  

    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();  
        cout << "Area: " << shapes[i]->area() << endl;  
    }

    return 0;
}
