#include "my_lib.h"

class TOY
{
public:
    TOY(const std::string& _name):name(_name) {}
    TOY():TOY("some toy") {}
    ~TOY() {
        std::cout << "Toy " << name << " was dropped " << std::endl;
    }
    std::string getToyName()
    {
        return name;
    }
    void setOwner(const std::string& _owner){
        owner = _owner;
    }
    std::string getOwner(){
        return owner;
    }
private:

    std::string name;
    std::string owner;

};

class DOG
{
public:

    DOG(const std::string& _name, const int& _age):name(_name) {
        if(_age < 0 || age > 30) age = 0;
        else age = _age;
    }
    DOG(const std::string& _name): DOG(_name,0) {}
    DOG(): DOG("undefined",0) {}

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
    void setName(const std::string& _name) {
        name=_name;
    }

    void getToy(const std::shared_ptr<TOY>& _some_toy) {
        if(_some_toy.use_count()==1) {
            some_toy = _some_toy;
            _some_toy->setOwner(this->name);
            std::cout << this->name << " got toy." << std::endl;
        }
        else if (_some_toy->getOwner()==this->name) {  std::cout << "\nVav\n\n"; }
        else {
            std::cout << this->name << " can't got toy! ";
            std::cout << _some_toy->getToyName() << " is bizy by " <<_some_toy->getOwner() << std::endl;
        }

    }

    void dropToy(const std::shared_ptr<TOY>& _some_toy) {
        if (_some_toy->getOwner()==this->name) {
            std::cout << "The toy – " << _some_toy->getToyName() << " was dropped by " << _some_toy->getOwner() << std::endl;
            some_toy.reset();
        } else {
            std::cout << "\nVav Vav\n\n";
        }

    }
private:

    std::string name;
    int age;
    std::shared_ptr<TOY> some_toy;
};

int getRandom(int ceed)
{
    return  std::rand() % ceed;
}

int task1()
{

#if 1
    std::srand(std::time(nullptr));
    std::cout<<"Input toy name: ";
    std::string toy_name;
    std::cin >> toy_name;
    std::shared_ptr<TOY> some_toy = std::make_shared<TOY>(toy_name);
    std::cout << "We have a toy " << some_toy->getToyName() << '!' << std::endl << std::endl;

    std::cout << "How much dogs do u have? ";
    int count;
    std::cin >> count;
    DOG** dogs = new DOG * [count];

    for (int i=0; i<count; ++i)
    {
        std::cout << "Input name and age of dog: ";
        std::string name;
        int age;
        std::cin >> name >> age;
        dogs[i] = new DOG(name,age);

    }

    int i=0;
    while (i<10)
    {

        for (int j=0; j<count; ++j)
        {
            dogs[getRandom(count)]->getToy(some_toy);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            dogs[getRandom(count)]->dropToy(some_toy);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        ++i;
    }

    delete dogs;

    std::cout << "\n\n\n\n\n";

#endif

}