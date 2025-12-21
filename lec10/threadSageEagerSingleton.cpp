
#include<iostream>

using namespace std;

class singleton{
    private:
    static singleton* instance;
    singleton(){
        cout << "Singleton Constructor called" << endl;
    }

    public:
    static singleton* getInstance(){
        return instance;
    }
};

singleton* singleton::instance = new singleton();


int main(){

    singleton* s1 = singleton::getInstance();
    singleton* s2 = singleton::getInstance();

    cout <<(s1 == s2) << endl;
    return 0;
}