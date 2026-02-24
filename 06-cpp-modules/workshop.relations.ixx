module;
#include <string>

export module workshop:relations;
import :types;

export auto assignLead(Team& team, Person& person) -> void
{
    team.lead = &person;
    person.team = &team;
}

export auto describe(const Person& person) -> std::string
{
    if (person.team == nullptr) {
        return person.name + " has no team";
    }
    return person.name + " leads team " + person.team->name;
}

export auto describe(const Team& team) -> std::string
{
    if (team.lead == nullptr) {
        return team.name + " has no lead";
    }
    return team.name + " is led by " + team.lead->name;
}
