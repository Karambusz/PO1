#ifndef user_h
#define user_h
#include <string>
#include <iostream>
#include <exception>
#include <memory>


class User {
private:
    std::string name;
public:
    User(const std::string str):name(str) {
        std::cout<<"Creating User "<<name<<std::endl;
    }
    void authorize(bool status){
        if(status == true){
            return;
        } else{
            std::string tmp = "Authorisation for User " + name + " was not granted.";
            throw tmp;
        }
    }
    std::string get_name() const{return name;}
    
    ~User(){
        std::cout<<"Deleting User "<<name<<std::endl;
    }
};

class UserArray{
private:
    User** tab;
    int size;
public:
    UserArray(const int n):size(n){
        tab = new User *[size];    
    }
    void set(const int index, User* user){
        if(index >=size){
            delete user;
            std::unique_ptr<UserArray> wsk(this);
            throw wsk;
        }else{
            tab[index] = user;
        }
    }
    User* get(int i){
        return tab[i];
    }
    ~UserArray(){
        if(tab){
            for(int i = 0; i < size; i++){
                delete tab[i];
            }
        }
        delete [] tab;
    }
    
    
};


#endif