#include <print>

import workshop;

auto main() -> int
{
    std::println("--- C++ Modules ---");
    std::println("{}", moduleSummary());
    std::println("{}", circularImportRule());
    std::println("");

    Team graphics { "Graphics" };
    Person ada { "Ada" };

    assignLead(graphics, ada);

    std::println("--- Forward declarations + partitions ---");
    std::println("{}", describe(ada));
    std::println("{}", describe(graphics));

    return 0;
}
