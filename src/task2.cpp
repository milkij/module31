#include "my_lib.h"

class SHARED_PTR_TOY
{
public:
    SHARED_PTR_TOY(const std::string& _name):name(_name) {
        *count+=1;
        std::cout << "  constructor  "<< this <<"  ----- count =  >>>  " << *count << std::endl;
    }
    SHARED_PTR_TOY(): SHARED_PTR_TOY("underfind") {};

    ~SHARED_PTR_TOY() {
        *count-=1;
        if (count!= nullptr) std::cout << "  distructor "<< this <<"  ----- count =  >>>  " << *count << std::endl;
        else std::cout << "  distructor "<< this << std::endl;
        if(*count==0) {
            delete count;
            std::cout << "delete count" << std::endl;
        }
    }

    SHARED_PTR_TOY (const SHARED_PTR_TOY* other)
    {
       this->name=other->name;
       count=other->count;
       *count+=1;
        std::cout << "  constructor(*)  "<< this <<"  ----- count =  >>>  " << *count << std::endl;


    }
    SHARED_PTR_TOY (const SHARED_PTR_TOY& other)
    {
        this->name=other.name;
        this->count=other.count;
        *count+=1;
        std::cout << "  constructor(&)  "<< this <<"  ----- count =  >>>  " << *count << std::endl;

    }

    SHARED_PTR_TOY& operator=(const SHARED_PTR_TOY& other)
    {
        this->name=other.name;
        this->count=other.count;
        *count+=1;
        std::cout << "  constructor(&)  "<< this <<"  ----- count =  >>>  " << *count << std::endl;
        return *this;
    }

    int getCount()
    {
        return *count;
    }

    std::string getName()
    {
        return name;
    }

    void reset () {
        *count-=1;
        std::cout << "  distructor "<< this <<"  ----- count =  >>>  " << *count << std::endl;
        if(*count==0) {
            delete count;
            std::cout << "delete count" << std::endl;
        }
    }
private:
    std::string name;
    int* count = new int(0);
};



int task2()
{
    SHARED_PTR_TOY* a = new SHARED_PTR_TOY("ball");
    SHARED_PTR_TOY* b = new SHARED_PTR_TOY(a);
    std::cout << "get count = " << b->getCount() << std::endl;
    delete a;
    std::cout << "get count = " << b->getCount() << std::endl;
    delete b;
    std::cout << "\n\n\n\n\n";
    SHARED_PTR_TOY c("bone");
    SHARED_PTR_TOY d(c);
    std::cout << "get count = " << c.getCount() << std::endl;
    c.reset();
    std::cout << "get count = " << d.getCount() << std::endl;
    d.reset();
    std::cout << "\n\n\n\n\n";
    SHARED_PTR_TOY e("jack");
    std::cout << "get count e = " << e.getCount() << std::endl;
    SHARED_PTR_TOY f = e;
    std::cout << "get count f = " << f.getCount() << std::endl;
    e.reset();
    std::cout << "get count f again = " << f.getCount() << std::endl;

    std::cout << "\n\n\n\n\n";
}