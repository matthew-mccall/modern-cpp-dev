module;
#include <string>

module workshop;

auto moduleSummary() -> std::string
{
    return "Module interface + partitions + implementation unit are active";
}

auto circularImportRule() -> std::string
{
    return "Modules cannot form cyclic imports; use acyclic partitions and forward declarations for cross-references";
}
