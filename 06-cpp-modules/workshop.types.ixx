module;
#include <string>

export module workshop:types;

export struct Team;

export struct Person {
    std::string name;
    Team* team = nullptr;
};

export struct Team {
    std::string name;
    Person* lead = nullptr;
};
