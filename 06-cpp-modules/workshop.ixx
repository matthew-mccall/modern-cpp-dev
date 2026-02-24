module;
#include <cstddef>
#include <string>

export module workshop;

export import :types;
export import :relations;

export auto moduleSummary() -> std::string;
export auto circularImportRule() -> std::string;

module :private;

constexpr std::size_t privateFragmentMarker = 1;
static_assert(privateFragmentMarker == 1);
