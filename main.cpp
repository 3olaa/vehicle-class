// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II
// program Name: .cpp
// last Modification Date: /10/2018
// Author,Id and Group: Ola Sameh - 20170165 - G8
// Teaching Assistant: Eng.Sara Hassan , Eng.Khloud Khaled

#include <iostream>

using namespace std;
class Person
{
private:
    string name;
public:
    Person()
    {
        name = "";
    }
    Person(string the_name)
    {
        name = the_name;
    }
    Person(const Person& the_name)
    {
        name  = the_name.name;
    }
    Person(const char* the_name)
    {
        name = the_name;
    }
    string getName() const /*mutator and accessor member function*/
    {
        return name;
    }
    Person& operator =(const Person& object)
    {
        this -> name = object.name;
        return *this;
    }
    friend istream& operator >>(istream& in,Person& person_object);
    friend ostream& operator <<(ostream& out,const Person& person_object);

};
istream& operator >>(istream& in, Person& person_object)
{
    in >> person_object.name;
    return in;
}
ostream& operator <<(ostream& out, const Person& person_object)
{
    out << person_object.name;
    return out;
}

class Vehicle
{
protected:
    string mName;
    int nCyl;
    Person owner;
public:
    Vehicle()
    {
        mName = "No Manufacturer";
        nCyl = 0;
        owner = "No Owner";
    }
    Vehicle(string n, int numCyl, const Person& o)
    {
        mName = n;
        nCyl = numCyl;
        owner = o;
    }
    Vehicle(const Vehicle& V)  //copy constructor
    {
        mName= V.mName;
        nCyl= V.nCyl;
        owner= V.owner;
    }
    Vehicle& operator =(const Vehicle& V)
    {
        this->mName = V.mName;
        this->nCyl = V.nCyl;
        this->owner = V.owner;
        return *this;
    }
    string getMName()
    {
        return mName;
    }
    int getNumCyl()
    {
        return nCyl;
    }
    Person getOwner()
    {
        return owner;
    }
    void print()
    {
        cout<<"Manufacturer's name: "<<mName<<endl;
        cout<<"Number of cylinders = "<<nCyl<<endl;
        cout<< "owner: "<<owner<<endl;
    }

};
class Truck : public Vehicle
{
private:
    double capTons;
    int capPounds;
public:
    Truck()
    {
        capTons = 0.0;
        capPounds = 0;
    }
    Truck(double CapT, int CapP, string mName, int nCyl, const Person& Owner): Vehicle(mName, nCyl, Owner)
    {
        capTons = CapT;
        capPounds = CapP;
    }
    Truck(const Truck& T): Vehicle(T)
    {
        capTons=T.capTons;
        capPounds=T.capPounds;
    }
    Truck&operator =(const Truck& T)
    {
        Vehicle::operator =(T);
        capTons = T.capTons;
        capPounds = T.capPounds;
        return *this;
    }
    double getCapTons()
    {
        return capTons;
    }
    int getCapPounds()
    {
        return capPounds;
    }
    void printInfo()
    {
        print();
        cout<<"Load capacity per = "<<capTons<<" Ton"<<endl;
        cout<<"Towing capacity = "<<capPounds<<" pound"<<endl;
    }

};
int main()
{

    Vehicle v1("Ford", 6, "Olaa");
    v1.print();
    cout<<endl;

    Truck t1(80.1, 1600, "Mercedes", 8, "Olaa");
    t1.printInfo();
    cout<<endl;

    return 0;
}
