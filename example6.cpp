#include <cstdio>
#include <memory>
#include <string>
#include <cstdio>
using ShoppingList = std::shared_ptr<std::FILE>;
auto deleter = [](std::FILE* f){fclose(f);};
ShoppingList makeFile(const char* filename, const char* flags)
{
    try {
    return ShoppingList(fopen(filename,flags), deleter);
    }
    catch (...)
    {
    return nullptr;
    }
}

class Partner
{
public:
    void addToFile(std::string element)
    {
        if(shoppingList==nullptr) return;
        fprintf(shoppingList.get(), "%s\n", element.c_str());
    }
    ShoppingList shoppingList;
};

int main()
{
    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");
}
