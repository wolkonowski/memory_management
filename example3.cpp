#include <iostream>
#include <stdexcept>
class KWException : public std::logic_error
{
public:
using std::logic_error::what;
KWException(const char* arg)
:std::logic_error(arg){
}
virtual const char* what(){

return std::logic_error::what();
}
};
void validateArguments(int argc)
{
    if(argc != 2)
    {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class Resource
{
public:
    void use(const char* arg)
    {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd')
        {
            throw KWException("Passed d. d is prohibited.");
        }
    }
};

int main(int argc, char* argv[])
{
    validateArguments(argc);

    const char* argument = argv[1];
    Resource* rsc = new Resource();
    try
    {
        rsc->use(argument);
    }
    catch (KWException& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete rsc;
    return 0;
}

